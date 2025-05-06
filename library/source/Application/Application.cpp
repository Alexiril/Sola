#include "Application/Application.hpp"
#include "Exception/ApplicationException.hpp"
#include "Helpers/FileSystem.hpp"
#include "Logger/Severity.hpp"
#include "Python/API.hpp"

namespace Sola
{
    namespace Application
    {
        Application *Application::instance = nullptr;

        Application *Application::init_application(bool is_editor, const std::string &project_dir, u64 argc,
                                                   char *const *argv, const std::string &app_name,
                                                   const std::string &app_version, const std::string &app_identifier,
                                                   const std::string &app_creator, const std::string &app_copyright,
                                                   const std::string &app_url)
        {
            if (instance != nullptr)
            {
                throw std::runtime_error("Application is already initialized");
            }

            instance = new Application(is_editor, project_dir, argc, argv, app_name, app_version, app_identifier,
                                       app_creator, app_copyright, app_url);

            instance->initialize_python();
            instance->initialize_project();
            instance->initialize_sdl();

            return instance;
        }

        Application *Application::get() noexcept { return instance; }

        bool Application::is_editor() const { return is_editor_; }

        const std::string &Application::get_project_dir() const noexcept { return app_project_dir; }

        const std::string &Application::get_name() const noexcept { return app_name; }

        const std::string &Application::get_version() const noexcept { return app_version; }

        const std::string &Application::get_identifier() const noexcept { return app_identifier; }

        const std::string &Application::get_creator() const noexcept { return app_creator; }

        const std::string &Application::get_copyright() const noexcept { return app_copyright; }

        const std::string &Application::get_url() const noexcept { return app_url; }

        PyObject *Sola::Application::Application::get_project_configuration(void) const noexcept
        {
            return project_configuration;
        }

        void Sola::Application::Application::set_project_configuration(PyObject *configuration)
        {
            Py_XDECREF(project_configuration);
            project_configuration = configuration;
            Py_XINCREF(project_configuration);
        }

        Application::Application(bool is_editor, const std::string &project_dir, u64 argc, char *const *argv,
                                 const std::string &app_name, const std::string &app_version,
                                 const std::string &app_identifier, const std::string &app_creator,
                                 const std::string &app_copyright, const std::string &app_url)
            : is_editor_(is_editor), app_project_dir(project_dir), app_name(app_name), app_version(app_version),
              app_identifier(app_identifier), app_creator(app_creator), app_copyright(app_copyright), app_url(app_url),
              modules(), cmd_arguments_count(argc), cmd_arguments(argv), project_configuration(nullptr)
        {
        }

        Application::~Application()
        {
            Py_XDECREF(project_configuration);

            quit_python();
            quit_sdl();
        }

        void Application::initialize_python()
        {
            /* -- Initializing Python interpreter -- */

            PyConfig config;
            PyConfig_InitPythonConfig(&config);
            config.dev_mode = is_editor_ ? 1 : 0;
            PyStatus status = PyConfig_SetBytesArgv(&config, cmd_arguments_count, cmd_arguments);
            if (status._type != PyStatus::_PyStatus_TYPE_OK)
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    std::string("Python initialization error: ") + status.err_msg, Logger::Severity::fatal);
            }
            status = PyConfig_SetString(&config, &config.home,
                                        Helpers::FileSystem::get_executable_directory().wstring().c_str());
            if (status._type != PyStatus::_PyStatus_TYPE_OK)
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    std::string("Python initialization error: ") + status.err_msg, Logger::Severity::fatal);
            }
            Python::InternalModule module = {Python::API::module_name, Python::API::create_python_module};
            interpreter = std::make_unique<Python::Interpreter>(config, std::array<Python::InternalModule, 1>{module});
            if (!interpreter->IsInitialized())
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    "Python interpreter was not initialized", Logger::Severity::fatal);
            }
            if (!interpreter->ImportModule("Sola"))
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    "Couldn't load Sola core python module", Logger::Severity::fatal);
            }

            /* -- Python interpreter is ready -- */
        }

        void Application::initialize_project()
        {
            /* -- Initialize project -- */

            PyObject *py_project_dir = PyUnicode_FromString(app_project_dir.c_str());
            if (py_project_dir == 0)
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    "Couldn't convert project directory to Python Unicode: " + app_project_dir,
                    Logger::Severity::fatal);
            }

            if (!interpreter->RunFunction("Sola", "sola_init", {}, {{"project_dir", py_project_dir}}).has_value())
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    "Sola core python module was not able to initialize the "
                    "application",
                    Logger::Severity::fatal);
            }
            py_project_dir = nullptr;

            // TODO#2
            modules.push_back(Module::VIDEO);

            /* -- Project is ready to be started -- */
        }

        void Application::initialize_sdl()
        {
            /* -- Initializing SDL3 -- */

            // TODO#3

            set_sdl_metadata(SDL_PROP_APP_METADATA_NAME_STRING, app_name.c_str());
            set_sdl_metadata(SDL_PROP_APP_METADATA_VERSION_STRING, app_version.c_str());
            set_sdl_metadata(SDL_PROP_APP_METADATA_IDENTIFIER_STRING, app_identifier.c_str());
            set_sdl_metadata(SDL_PROP_APP_METADATA_CREATOR_STRING, app_creator.c_str());
            set_sdl_metadata(SDL_PROP_APP_METADATA_COPYRIGHT_STRING, app_copyright.c_str());
            set_sdl_metadata(SDL_PROP_APP_METADATA_URL_STRING, app_url.c_str());

            u32 init_modules_flags = 0;

            for (auto &&module : modules)
            {
                init_modules_flags |= ModuleFunctions::to_sdlcode(module);
            }

            if (!SDL_InitSubSystem(init_modules_flags))
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    std::string("Couldn't initialize SDL: ") + SDL_GetError(), Logger::Severity::fatal);
            }

            /* -- SDL3 is ready -- */
        }

        void Application::set_sdl_metadata(const char *metadata_name, const std::string &value)
        {
            if (!SDL_SetAppMetadataProperty(metadata_name, value.c_str()))
            {
                throw Exception::ApplicationException::ApplicationInitializationException(
                    std::string("Couldn't set SDL metadata: ") + SDL_GetError(), Logger::Severity::fatal);
            }
        }

        void Application::quit_python() {}

        void Application::quit_sdl()
        {
            /* -- Cleaning and quitting SDL3 -- */

            SDL_Quit();

            /* -- SDL3 finished -- */
        }
    } // namespace Application
} // namespace Sola

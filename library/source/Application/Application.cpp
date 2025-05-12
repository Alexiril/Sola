#include "Application/Application.hpp"
#include "Graphics/Color.hpp"
#include "Helpers/FileSystem.hpp"
#include "Logger/Severity.hpp"
#include "Python/API.hpp"
#include "tracy/Tracy.hpp"

namespace Sola
{
    namespace Application
    {
        Application *Application::instance = nullptr;

        std::expected<Application *, ApplicationError>
        Application::init_application(bool is_editor, const std::string &project_dir, u64 argc, char *const *argv,
                                      const std::string &app_name, const std::string &app_version,
                                      const std::string &app_identifier, const std::string &app_creator,
                                      const std::string &app_copyright, const std::string &app_url)
        {
#ifdef SOLA_PROFILER_INTERNAL_SECTION
            ZoneScopedC(Graphics::Color::Amber);
#endif
            if (instance != nullptr)
            {
                return std::unexpected(ApplicationError::AppIsAlreadyInitialized);
            }

            instance = new Application(is_editor, project_dir, argc, argv, app_name, app_version, app_identifier,
                                       app_creator, app_copyright, app_url);

            instance->initialize_python();
            instance->initialize_project();
            instance->initialize_sdl();

            return instance;
        }

        Application *Application::get() noexcept { return instance; }

        bool Application::is_editor() const noexcept { return is_editor_; }

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
            Py_XDECREF(project_configuration); // if it exists already, decrement the reference count
            project_configuration = configuration;
            Py_XINCREF(project_configuration); // increment the reference count for the new configuration
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

        std::expected<void, ApplicationError> Application::initialize_python()
        {
            /* -- Initializing Python interpreter -- */

            PyConfig config;
            PyConfig_InitPythonConfig(&config);
            config.dev_mode = is_editor_ ? 1 : 0;
            PyStatus status = PyConfig_SetBytesArgv(&config, cmd_arguments_count, cmd_arguments);
            if (status._type != PyStatus::_PyStatus_TYPE_OK)
            {
                print_error(status.err_msg);
                return std::unexpected(ApplicationError::PythonInitializationFailed);
            }
            std::expected<std::filesystem::path, Helpers::FileSystem::FileSystemError> exe_dir =
                Helpers::FileSystem::get_executable_directory();
            if (exe_dir.has_value())
            {
                status = PyConfig_SetString(&config, &config.home, exe_dir.value().wstring().c_str());
                if (status._type != PyStatus::_PyStatus_TYPE_OK)
                {
                    print_error(status.err_msg);
                    return std::unexpected(ApplicationError::PythonInitializationFailed);
                }
            }
            Python::InternalModule module = {Python::API::module_name, Python::API::create_python_module};
            interpreter = std::make_unique<Python::Interpreter>(config, std::array<Python::InternalModule, 1>{module});
            if (!interpreter->IsInitialized())
            {
                print_error("Python interpreter was not initialized");
                return std::unexpected(ApplicationError::PythonInitializationFailed);
            }
            if (!interpreter->ImportModule("Sola"))
            {
                print_error("Couldn't import Sola core python module");
                return std::unexpected(ApplicationError::SolaModuleImportFailed);
            }

            /* -- Python interpreter is ready -- */

            return {};
        }

        std::expected<void, ApplicationError> Application::initialize_project()
        {
            /* -- Initialize project -- */

            PyObject *py_project_dir = PyUnicode_FromString(app_project_dir.c_str());
            if (py_project_dir == 0)
            {
                print_error("Couldn't convert project directory to Python Unicode: " + app_project_dir);
                return std::unexpected(ApplicationError::ProjectInitializationFailed);
            }

            if (!interpreter->RunFunction("Sola", "sola_init", {}, {{"project_dir", py_project_dir}}).has_value())
            {
                print_error("Couldn't initialize project: " + app_project_dir);
                return std::unexpected(ApplicationError::ProjectInitializationFailed);
            }
            py_project_dir = nullptr;

            // TODO#2
            modules.push_back(Module::video);

            /* -- Project is ready to be started -- */

            return {};
        }

        std::expected<void, ApplicationError> Application::initialize_sdl()
        {
            /* -- Initializing SDL3 -- */

            // TODO#3

            set_sdl_metadata(SDL_PROP_APP_METADATA_NAME_STRING, app_name);
            set_sdl_metadata(SDL_PROP_APP_METADATA_VERSION_STRING, app_version);
            set_sdl_metadata(SDL_PROP_APP_METADATA_IDENTIFIER_STRING, app_identifier);
            set_sdl_metadata(SDL_PROP_APP_METADATA_CREATOR_STRING, app_creator);
            set_sdl_metadata(SDL_PROP_APP_METADATA_COPYRIGHT_STRING, app_copyright);
            set_sdl_metadata(SDL_PROP_APP_METADATA_URL_STRING, app_url);

            u32 init_modules_flags = SDL_INIT_VIDEO;

            // u32 to_sdlcode(Module module)
            // {
            //     switch (module)
            //     {
            //         case Module::audio:
            //             return SDL_INIT_AUDIO;
            //         case Module::video:
            //             return SDL_INIT_VIDEO;
            //         case Module::joystick:
            //             return SDL_INIT_JOYSTICK;
            //         case Module::haptic:
            //             return SDL_INIT_HAPTIC;
            //         case Module::gamepad:
            //             return SDL_INIT_GAMEPAD;
            //         case Module::sensor:
            //             return SDL_INIT_SENSOR;
            //         case Module::camera:
            //             return SDL_INIT_CAMERA;
            //         case Module::unknown:
            //         default:
            //             return 0;
            //     }
            // }

            // init_modules_flags =
            //     std::accumulate(modules.begin(), modules.end(), init_modules_flags,
            //                     [](u32 acc, Module module) { return acc | ModuleFunctions::to_sdlcode(module); });

            if (!SDL_InitSubSystem(init_modules_flags))
            {
                print_error("Couldn't initialize SDL: " + std::string(SDL_GetError()));
                return std::unexpected(ApplicationError::SDLInitializationFailed);
            }

            /* -- SDL3 is ready -- */

            return {};
        }

        std::expected<void, ApplicationError> Application::set_sdl_metadata(const char *metadata_name,
                                                                            const std::string &value)
        {
            if (!SDL_SetAppMetadataProperty(metadata_name, value.c_str()))
            {
                print_error("Couldn't set SDL metadata: " + std::string(SDL_GetError()));
                return std::unexpected(ApplicationError::SDLInitializationFailed);
            }

            return {};
        }

        void Application::quit_python()
        {
            /* -- Cleaning and quitting Python interpreter -- */

            if (interpreter != nullptr)
            {
                interpreter.reset();
            }

            /* -- Python interpreter finished -- */
        }

        void Application::quit_sdl()
        {
            /* -- Cleaning and quitting SDL3 -- */

            SDL_Quit();

            /* -- SDL3 finished -- */
        }
    } // namespace Application
} // namespace Sola

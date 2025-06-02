#include <tracy/Tracy.hpp>

#include "Application/Application.hpp"
#include "Graphics/Color.hpp"
#include "Helpers/FileSystem.hpp"
#include "Logger/Severity.hpp"
#include "Python/API/API.hpp"

namespace Sola::Application {
    Application *Application::Instance = nullptr;

    auto Application::initApplication(bool IsEditor, const std::string &AppProjectDir, u64 Argc, char *const *Argv,
                                      const std::string &AppName, const std::string &AppVersion,
                                      const std::string &AppIdentifier, const std::string &AppCreator,
                                      const std::string &AppCopyright, const std::string &AppUrl)
        -> std::expected<Application *, ApplicationError> {
#ifdef SOLA_PROFILER_INTERNAL_SECTION
        ZoneScopedC(Graphics::Color::Amber);
#endif
        if (Instance != nullptr) {
            return std::unexpected(ApplicationError::AppIsAlreadyInitialized);
        }

        Instance = new Application(IsEditor, AppProjectDir, Argc, Argv, AppName, AppVersion, AppIdentifier, AppCreator,
                                   AppCopyright, AppUrl);

        auto pythonInitResult = Instance->initializePython();
        if (!pythonInitResult.has_value()) {
            delete Instance;
            Instance = nullptr;
            return std::unexpected(pythonInitResult.error());
        }
        auto projectInitResult = Instance->initializeProject();
        if (!projectInitResult.has_value()) {
            delete Instance;
            Instance = nullptr;
            return std::unexpected(projectInitResult.error());
        }
        auto sdlInitResult = Instance->initializeSDL();
        if (!sdlInitResult.has_value()) {
            delete Instance;
            Instance = nullptr;
            return std::unexpected(sdlInitResult.error());
        }

        return Instance;
    }

    auto Application::get() noexcept -> Application * { return Instance; }

    auto Application::isEditor() const noexcept -> bool { return IsEditor; }

    auto Application::getProjectDir() const noexcept -> const std::string & { return AppProjectDir; }

    auto Application::getName() const noexcept -> const std::string & { return AppName; }

    auto Application::getVersion() const noexcept -> const std::string & { return AppVersion; }

    auto Application::getIdentifier() const noexcept -> const std::string & { return AppIdentifier; }

    auto Application::getCreator() const noexcept -> const std::string & { return AppCreator; }

    auto Application::getCopyright() const noexcept -> const std::string & { return AppCopyright; }

    auto Application::getUrl() const noexcept -> const std::string & { return AppUrl; }

    auto Sola::Application::Application::getProjectConfiguration() const noexcept -> PyObject * {
        return ProjectConfiguration;
    }

    void Sola::Application::Application::setProjectConfiguration(PyObject *configuration) {
        Py_XDECREF(ProjectConfiguration); // if it exists already, decrement the reference count
        ProjectConfiguration = configuration;
        Py_XINCREF(ProjectConfiguration); // increment the reference count for the new configuration
    }

    Application::Application(bool IsEditor, std::string ProjectDir, u64 Argc, char *const *Argv, std::string AppName,
                             std::string AppVersion, std::string AppIdentifier, std::string AppCreator,
                             std::string AppCopyright, std::string AppUrl)
        : IsEditor(IsEditor), AppProjectDir(std::move(ProjectDir)), AppName(std::move(AppName)),
          AppVersion(std::move(AppVersion)), AppIdentifier(std::move(AppIdentifier)), AppCreator(std::move(AppCreator)),
          AppCopyright(std::move(AppCopyright)), AppUrl(std::move(AppUrl)), CMDArgumentsCount(Argc), CMDArguments(Argv),
          ProjectConfiguration(nullptr), Interpreter(nullptr) {}

    Application::~Application() {
        Py_XDECREF(ProjectConfiguration);

        quitPython();
        quitSDL();
    }

    auto Application::initializePython() -> std::expected<void, ApplicationError> {
        /* -- Initializing Python interpreter -- */

        PyConfig Config;
        PyConfig_InitPythonConfig(&Config);
        Config.dev_mode = IsEditor ? 1 : 0;
        PyStatus status = PyConfig_SetBytesArgv(&Config, CMDArgumentsCount, CMDArguments);
        if (status._type != PyStatus::_PyStatus_TYPE_OK) {
            printError(status.err_msg);
            return std::unexpected(ApplicationError::PythonInitializationFailed);
        }
        std::expected<std::filesystem::path, Helpers::FileSystem::FileSystemError> exe_dir =
            Helpers::FileSystem::getExecutableDirectory();
        if (exe_dir.has_value()) {
            status = PyConfig_SetString(&Config, &Config.home, exe_dir.value().wstring().c_str());
            if (status._type != PyStatus::_PyStatus_TYPE_OK) {
                printError(status.err_msg);
                return std::unexpected(ApplicationError::PythonInitializationFailed);
            }
        }
        Python::InternalModule Module = {.ModuleName = Python::API::ModuleName,
                                         .moduleInit = Python::API::createPythonModule};
        Interpreter = std::make_shared<Python::Interpreter>(Config, std::vector<Python::InternalModule>{Module});
        if (!Interpreter->isInitialized()) {
            printError("Python interpreter was not initialized");
            return std::unexpected(ApplicationError::PythonInitializationFailed);
        }
        if (!Interpreter->importModule("Sola")) {
            printError("Couldn't import Sola core python module");
            return std::unexpected(ApplicationError::SolaModuleImportFailed);
        }

        /* -- Python interpreter is ready -- */

        return {};
    }

    auto Application::initializeProject() -> std::expected<void, ApplicationError> {
        /* -- Initialize project -- */

        PyObject *PyProjectDir = PyUnicode_FromString(AppProjectDir.c_str());
        if (PyProjectDir == nullptr) {
            printError("Couldn't convert project directory to Python Unicode: " + AppProjectDir);
            return std::unexpected(ApplicationError::ProjectInitializationFailed);
        }

        if (!Interpreter
                 ->runFunction(Interpreter->getAttribute("Sola", "Initializer").value_or(nullptr), "init", {},
                               {{"ProjectDir", PyProjectDir}})
                 .has_value()) {
            printError("Couldn't initialize project: " + AppProjectDir);
            return std::unexpected(ApplicationError::ProjectInitializationFailed);
        }
        PyProjectDir = nullptr;

        this->Modules.push_back(Module::Video);

        /* -- Project is ready to be started -- */

        return {};
    }

    auto Application::initializeSDL() -> std::expected<void, ApplicationError> {
        /* -- Initializing SDL3 -- */

        // TODO#3

        if (!setSDLMetadata(SDL_PROP_APP_METADATA_NAME_STRING, AppName).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }
        if (!setSDLMetadata(SDL_PROP_APP_METADATA_VERSION_STRING, AppVersion).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }
        if (!setSDLMetadata(SDL_PROP_APP_METADATA_IDENTIFIER_STRING, AppIdentifier).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }
        if (!setSDLMetadata(SDL_PROP_APP_METADATA_CREATOR_STRING, AppCreator).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }
        if (!setSDLMetadata(SDL_PROP_APP_METADATA_COPYRIGHT_STRING, AppCopyright).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }
        if (!setSDLMetadata(SDL_PROP_APP_METADATA_URL_STRING, AppUrl).has_value()) {
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }

        u32 InitModulesFlags = 0;

        // only for debug, not ready
        if (this->Modules[0] == Module::Video) {
            InitModulesFlags = SDL_INIT_VIDEO;
        }

        // u32 to_sdlcode(Module module)
        // {
        //     switch (module)
        //     {
        //         case Module::Audio:
        //             return SDL_INIT_AUDIO;
        //         case Module::Video:
        //             return SDL_INIT_VIDEO;
        //         case Module::Joystick:
        //             return SDL_INIT_JOYSTICK;
        //         case Module::Haptic:
        //             return SDL_INIT_HAPTIC;
        //         case Module::gamepad:
        //             return SDL_INIT_GAMEPAD;
        //         case Module::Sensor:
        //             return SDL_INIT_SENSOR;
        //         case Module::Camera:
        //             return SDL_INIT_CAMERA;
        //         case Module::Unknown:
        //         default:
        //             return 0;
        //     }
        // }

        // init_modules_flags =
        //     std::accumulate(modules.begin(), modules.end(), init_modules_flags,
        //                     [](u32 acc, Module module) { return acc | ModuleFunctions::to_sdlcode(module); });

        if (!SDL_InitSubSystem(InitModulesFlags)) {
            printError("Couldn't initialize SDL: " + std::string(SDL_GetError()));
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }

        /* -- SDL3 is ready -- */

        return {};
    }

    auto Application::setSDLMetadata(const char *metadata_name, const std::string &value)
        -> std::expected<void, ApplicationError> {
        if (!SDL_SetAppMetadataProperty(metadata_name, value.c_str())) {
            printError("Couldn't set SDL metadata: " + std::string(SDL_GetError()));
            return std::unexpected(ApplicationError::SDLInitializationFailed);
        }

        return {};
    }

    void Application::quitPython() {
        /* -- Cleaning and quitting Python interpreter -- */

        if (this->Interpreter != nullptr) {
            Interpreter.reset();
        }

        /* -- Python interpreter finished -- */
    }

    void Application::quitSDL() {
        /* -- Cleaning and quitting SDL3 -- */

        SDL_Quit();

        /* -- SDL3 finished -- */
    }

    auto Application::getPythonInterpreter() const noexcept -> std::shared_ptr<Python::Interpreter> {
        return Interpreter;
    }

} // namespace Sola::Application

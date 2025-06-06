#include "EditorInitializer/EditorInitializer.hpp"
#include "Application/Application.hpp"
#include "Logger/Logger.hpp"
#include "Python/Interpreter.hpp"

namespace Sola::Runtime::Editor {
    auto InitializerType::initializeApplication(i32 ArgumentsCount, char **Arguments)
        -> std::expected<void, InitializerError> {
        if (ArgumentsCount < 2) {
            printInfo("Incorrect amount of arguments for editor application. \nUsage is 'sola-runtime-editor "
                      "\"path-to-project-dir\" [...]'");
            return std::unexpected(InitializerError::InvalidArguments);
        }
        const std::string ProjectPath = Arguments[1];
        std::vector<Python::InternalModule> PythonModules = {};
        auto ApplicationPtr = Application::Application::initApplication(
            true, ProjectPath, ArgumentsCount, Arguments, "Sola Editor", SOLA_VERSION_STRING, SOLA_APP_IDENTIFIER,
            SOLA_APP_CREATOR, SOLA_APP_COPYRIGHT, SOLA_APP_URL, PythonModules);
        if (!ApplicationPtr.has_value()) {
            printInfo("Failed to initialize application.");
            switch (ApplicationPtr.error()) {
                case Application::ApplicationError::AppIsAlreadyInitialized:
                    printInfo("Application is already initialized.");
                    return std::unexpected(InitializerError::InitializationFailed);
                case Application::ApplicationError::PythonInitializationFailed:
                    printInfo("Python initialization failed.");
                    return std::unexpected(InitializerError::InitializationFailed);
                case Application::ApplicationError::SolaModuleImportFailed:
                    printInfo("Sola module import failed.");
                    return std::unexpected(InitializerError::InitializationFailed);
                case Application::ApplicationError::ProjectInitializationFailed:
                    printInfo("Project initialization failed.");
                    return std::unexpected(InitializerError::ProjectNotFound);
                case Application::ApplicationError::SDLInitializationFailed:
                    printInfo("SDL initialization failed.");
                    return std::unexpected(InitializerError::InitializationFailed);
                default:
                    return std::unexpected(InitializerError::InitializationFailed);
            }
        }

        std::weak_ptr<Python::Interpreter> Interpreter = ApplicationPtr.value()->getPythonInterpreter();
        if (Interpreter.expired()) {
            printInfo("Python interpreter is not initialized.");
            return std::unexpected(InitializerError::InitializationFailed);
        }

        if (!Interpreter.lock()->importModule("SolaEditor")) {
            printInfo("Failed to import SolaEditor module.");
            return std::unexpected(InitializerError::InitializationFailed);
        }

        printInfo("Editor application initialized successfully.");
        return {};
    }

    auto InitializerType::toString(InitializerError error) -> std::string {
        switch (error) {
            case InitializerError::InvalidArguments:
                return "Invalid arguments provided.";
            case InitializerError::InitializationFailed:
                return "Application initialization failed.";
            case InitializerError::ProjectNotFound:
                return "Project not found.";
            case InitializerError::UnsupportedVersion:
                return "Unsupported version of the application.";
            case InitializerError::UnknownError:
                [[fallthrough]];
            default:
                return "An unknown error occurred during initialization.";
        }
    }
} // namespace Sola::Runtime::Editor

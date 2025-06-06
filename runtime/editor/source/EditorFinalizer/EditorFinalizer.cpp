#include "EditorFinalizer/EditorFinalizer.hpp"
#include "Application/Application.hpp"
#include "Logger/Logger.hpp"

namespace Sola::Runtime::Editor {
    auto FinalizerType::finalizeApplication() -> std::expected<void, FinalizerError> {
        if (Sola::Application::Application::get() == nullptr) {
            printInfo("Editor application is not initialized.");
            return std::unexpected(FinalizerError::FinalizationFailed);
        }
        printInfo("Finalizing editor application...");
        Application::Application::quitApplication();
        if (Sola::Application::Application::get() != nullptr) {
            printInfo("Editor application finalization failed.");
            return std::unexpected(FinalizerError::FinalizationFailed);
        }

        return {};
    }

    auto FinalizerType::toString(FinalizerError error) -> std::string {
        switch (error) {
            case FinalizerError::FinalizationFailed:
                return "Editor application finalization failed.";
            case FinalizerError::UnknownError:
                [[fallthrough]];
            default:
                return "An unknown error occurred during editor application finalization.";
        }
    }
} // namespace Sola::Runtime::Editor

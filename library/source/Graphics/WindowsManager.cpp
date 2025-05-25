#include "Graphics/WindowsManager.hpp"
#include "Application/Application.hpp"
#include "Exceptions/GeneralException.hpp"

namespace Sola::Graphics::WindowsManager {
    /// @brief Little bit too much complicated class that simply stores the SDL message box data and the
    /// callback function. It is only used inside this C++ file to transfer the data from the showMessageBox
    /// Function to the main thread callback. **It should not** be used for anything else! Likewise, it is
    /// simply a temporary data holder.
    /// @attention Does allocate memory via "new" operator. The destructor should be properly called; otherwise
    /// there might be a chance for a memory leak.
    class MessageBoxDataWithCallback {
    public:
        /// @brief Constructor for the message box data. It initializes all the members of the structure.
        /// @param Severity The severity level of the message box.
        /// @param Title The title of the message box.
        /// @param Message The message to be displayed in the message box.
        /// @param Buttons A vector of button data for the message box.
        /// @param Function A callback function to be called when a button is clicked.
        MessageBoxDataWithCallback(Logger::Severity Severity, const std::string &Title, const std::string &Message,
                                   const std::vector<ButtonData> &Buttons, const std::function<void(i32)> &Function)
            : Function(Function) {
            // -- delete required --
            MBData = new SDL_MessageBoxData();
            MBData->flags = SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT;
            switch (Severity) {
                case Logger::Severity::Info:
                    MBData->flags |= SDL_MESSAGEBOX_INFORMATION;
                    break;
                case Logger::Severity::Warning:
                    MBData->flags |= SDL_MESSAGEBOX_WARNING;
                    break;
                case Logger::Severity::Error:
                    [[fallthrough]];
                case Logger::Severity::Fatal:
                    MBData->flags |= SDL_MESSAGEBOX_ERROR;
                    break;
                case Logger::Severity::None:
                case Logger::Severity::Debug:
                default:
                    break;
            }
            MBData->window = nullptr;
            MBData->title = Title.c_str();
            MBData->message = Message.c_str();
            MBData->colorScheme = nullptr;
            MBData->numbuttons = static_cast<i32>(Buttons.size());

            // -- delete[] required --
            auto SDLButtons = new SDL_MessageBoxButtonData[Buttons.size()];
            SDL_MessageBoxButtonData *CurrentButton = SDLButtons;
            for (auto &&CurrentButtonData : Buttons) {
                CurrentButton->buttonID = CurrentButtonData.ButtonID;
                u32 flags = 0;
                if (CurrentButtonData.IsEscapeDefault) {
                    flags |= SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT;
                }
                if (CurrentButtonData.IsEnterDefault) {
                    flags |= SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT;
                }
                CurrentButton->flags = flags;
                CurrentButton->text = CurrentButtonData.Text.c_str();
                CurrentButton += 1; // working with the next button
            }

            MBData->buttons = SDLButtons;
        }

        /// @brief Copy constructor for the message box data is prohibited.
        MessageBoxDataWithCallback(const MessageBoxDataWithCallback &) = delete;

        /// @brief Normal move constructor
        /// @param Other the other instance to move from.
        MessageBoxDataWithCallback(MessageBoxDataWithCallback &&Other) noexcept
            : Function(std::move(Other.Function)), MBData(std::exchange(Other.MBData, nullptr)) {}

        // clang-tidy keeps saying this destructor may be trivial, but I suppose
        // if we make it = default, there will be a memory leak, because pointers
        // won't be deleted correctly.

        // NOLINTBEGIN(modernize-use-equals-default)

        /// @brief Simple destructor. Deletes the heap data allocated in the constructor
        /// @todo Why don't I use std::unique_ptr again?...
        ~MessageBoxDataWithCallback() {
            delete[] MBData->buttons;
            delete MBData;
        }

        // NOLINTEND(modernize-use-equals-default)

        /// @brief Move assignment operator for the MessageBoxDataWithCallback class.
        /// @param Other the MessageBoxDataWithCallback object to move from.
        /// @return MessageBoxDataWithCallback& A reference to the current object
        /// after the assignment.
        auto operator=(MessageBoxDataWithCallback &&Other) noexcept -> MessageBoxDataWithCallback & {
            Function = std::move(Other.Function);
            MBData = std::exchange(Other.MBData, nullptr);
            return *this;
        }

        /// @brief The data directly used in SDL_ShowMessageBox
        SDL_MessageBoxData *MBData;
        /// @brief The callback function
        std::function<void(i32)> Function;
    };

    /// @brief This function is called in the main thread by SDL to actually show the message box.
    /// @param UserData the pointer to the MessageBoxDataWithCallback object that contains all the data needed
    /// to show the message box.
    void SDLCALL showMessageBoxMainThreadCallback(void *UserData) {
        i32 *HitButton = new i32(-1);
        auto Data = static_cast<MessageBoxDataWithCallback *>(UserData);
        SDL_MessageBoxData *MBData = Data->MBData;
        bool ShowMBResult = SDL_ShowMessageBox(MBData, HitButton);
        if (!ShowMBResult) {
            printWarning("SDL_ShowMessageBox failed: " + std::string(SDL_GetError()));
            *HitButton = -2;
        }
        Data->Function(*HitButton);
        delete Data; // calling the MessageBoxDataWithCallback destructor and cleaning this manual memory
                     // control mess
    }

    auto showMessageBox(Logger::Severity Severity, const std::string &Title, const std::string &Message,
                        const std::vector<ButtonData> &Buttons, const std::function<void(i32)> &callback)
        -> std::expected<void, WindowsManagerError> {
        // -- delete required --
        auto *Data = new MessageBoxDataWithCallback(Severity, Title, Message, Buttons, callback);

        if (!SDL_RunOnMainThread(showMessageBoxMainThreadCallback, static_cast<void *>(Data), false)) {
            printWarning("WindowsManager::showMessageBox couldn't transfer execution to the main thread: " +
                         std::string(SDL_GetError()));
            return std::unexpected(WindowsManagerError::ShowMessageBoxFailed);
        }

        return {};
    }

    void showWarningMessageBox(const std::string &Message) {
        auto result = showMessageBox(Logger::Severity::Warning, "Sola warning", Message,
                                     {ButtonData(0, true, true, "Ignore")}, [](i32) {});
        if (!result.has_value()) {
            printWarning("WindowsManager::showWarningMessageBox failed: " +
                         std::to_string(static_cast<i32>(result.error())));
        }
    }

    void showErrorMessageBox(const std::string &Message) {
        auto result = showMessageBox(
            Logger::Severity::Error, "Sola error", Message,
            {ButtonData(0, true, false, "Ignore"), ButtonData(1, false, true, "Quit")}, [](i32 HitButton) {
                if (HitButton == 1) {
                    throw SOLA_GENERAL_EXCEPTION("Error message box was called and Quit button was hit.",
                                                 Logger::Severity::Fatal);
                }
            });
        if (!result.has_value()) {
            printWarning("WindowsManager::showErrorMessageBox failed: " +
                         std::to_string(static_cast<i32>(result.error())));
        }
    }

    void showFatalMessageBox(const std::string &Message) {
        auto result = showMessageBox(
            Logger::Severity::Fatal, "Sola Fatal", Message, {ButtonData(0, true, true, "Quit")},
            [](i32) { throw SOLA_GENERAL_EXCEPTION("Fatal message box was called.", Logger::Severity::Fatal); });

        if (!result.has_value()) {
            printWarning("WindowsManager::showFatalMessageBox failed: " +
                         std::to_string(static_cast<i32>(result.error())));
        }
    }

} // namespace Sola::Graphics::WindowsManager

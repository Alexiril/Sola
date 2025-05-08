#include "Graphics/WindowsManager.hpp"
#include "Application/Application.hpp"
#include "Exception/GeneralException.hpp"

namespace Sola
{
    namespace Graphics
    {
        namespace WindowsManager
        {
            // Is used only inside this file to transfer data from show_message_box to
            // main thread callback
            class MessageBoxDataWithCallback
            {
            public:
                MessageBoxDataWithCallback(Logger::Severity severity, const std::string &title,
                                           const std::string &message, const std::vector<ButtonData> &buttons,
                                           const std::function<void(i32)> &function)
                    : function(function)
                {
                    mbdata = new SDL_MessageBoxData();
                    mbdata->flags = SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT;
                    switch (severity)
                    {
                        case Logger::Severity::info:
                            mbdata->flags |= SDL_MESSAGEBOX_INFORMATION;
                            break;
                        case Logger::Severity::warning:
                            mbdata->flags |= SDL_MESSAGEBOX_WARNING;
                            break;
                        case Logger::Severity::error:
                        case Logger::Severity::fatal:
                            mbdata->flags |= SDL_MESSAGEBOX_ERROR;
                            break;
                        default:
                            break;
                    }
                    mbdata->window = nullptr;
                    mbdata->title = title.c_str();
                    mbdata->message = message.c_str();
                    mbdata->colorScheme = nullptr;
                    mbdata->numbuttons = static_cast<i32>(buttons.size());

                    // -- delete[] required --
                    SDL_MessageBoxButtonData *sdlbuttons = new SDL_MessageBoxButtonData[buttons.size()];
                    SDL_MessageBoxButtonData *current_button = sdlbuttons;
                    for (auto &&button_data : buttons)
                    {
                        current_button->buttonID = button_data.button_id;
                        u32 flags = 0;
                        if (button_data.is_escape_default)
                        {
                            flags |= SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT;
                        }
                        if (button_data.is_enter_default)
                        {
                            flags |= SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT;
                        }
                        current_button->flags = flags;
                        current_button->text = button_data.text.c_str();
                        current_button += 1; // working with the next button
                    }

                    mbdata->buttons = sdlbuttons;
                }

                MessageBoxDataWithCallback(const MessageBoxDataWithCallback &other) = delete;

                MessageBoxDataWithCallback(MessageBoxDataWithCallback &&other)
                    : function(std::move(other.function)), mbdata(std::exchange(other.mbdata, nullptr))
                {
                }

                ~MessageBoxDataWithCallback()
                {
                    delete[] mbdata->buttons;
                    delete mbdata;
                }

                MessageBoxDataWithCallback &operator=(MessageBoxDataWithCallback &&other)
                {
                    function = std::move(other.function);
                    mbdata = std::exchange(other.mbdata, nullptr);
                    return *this;
                }

                SDL_MessageBoxData *mbdata;
                std::function<void(int)> function;
            };

            void SDLCALL ShowMessageBoxMainThreadCallback(void *userdata)
            {
                i32 *hit_button = new i32(-1);
                MessageBoxDataWithCallback *data = static_cast<MessageBoxDataWithCallback *>(userdata);
                SDL_MessageBoxData *mbdata = data->mbdata;
                bool show_mb_result = SDL_ShowMessageBox(mbdata, hit_button);
                const std::function<void(i32)> &function = data->function;
                delete data;
                if (!show_mb_result)
                {
                    print_warning("SDL_ShowMessageBox failed: " + std::string(SDL_GetError()));
                }
                function(*hit_button);
            }

            std::expected<void, WindowsManagerError>
            show_message_box(Logger::Severity severity, const std::string &title, const std::string &message,
                             const std::vector<ButtonData> &buttons, const std::function<void(i32)> &callback)
            {
                // -- delete required --
                MessageBoxDataWithCallback *data =
                    new MessageBoxDataWithCallback(severity, title, message, buttons, callback);

                if (!SDL_RunOnMainThread(ShowMessageBoxMainThreadCallback, static_cast<void *>(data), false))
                {
                    print_warning("WindowsManager::show_message_box couldn't transfer execution to the main thread: " +
                                  std::string(SDL_GetError()));
                    return std::unexpected(WindowsManagerError::SHOW_MESSAGE_BOX_FAILED);
                }

                return {};
            }

            void show_warning_message_box(const std::string &message)
            {
                show_message_box(Logger::Severity::warning, "Sola warning", message,
                                 {ButtonData(0, true, true, "Ignore")}, [](i32) {});
            }

            void show_error_message_box(const std::string &message)
            {
                show_message_box(Logger::Severity::error, "Sola error", message,
                                 {ButtonData(0, true, false, "Ignore"), ButtonData(1, false, true, "Quit")},
                                 [](i32 choice)
                                 {
                                     if (choice == 1)
                                     {
                                         throw SOLA_GENERAL_EXCEPTION(
                                             "Error message box was called and Quit button was hit.",
                                             Logger::Severity::fatal);
                                     }
                                 });
            }

            void show_fatal_message_box(const std::string &message)
            {
                show_message_box(
                    Logger::Severity::fatal, "Sola fatal", message, {ButtonData(0, true, true, "Quit")}, [](i32)
                    { throw SOLA_GENERAL_EXCEPTION("Fatal message box was called.", Logger::Severity::fatal); });
            }

        } // namespace WindowsManager
    } // namespace Graphics
} // namespace Sola

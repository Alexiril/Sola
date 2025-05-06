#include "Graphics/WindowsManager.hpp"
#include "Application/Application.hpp"
#include "Exception/SDLException.hpp"

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

                    // -- delete[] --
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
                ~MessageBoxDataWithCallback()
                {
                    delete[] mbdata->buttons;
                    delete mbdata;
                }

                SDL_MessageBoxData *mbdata;
                const std::function<void(int)> &function;
            };

            void SDLCALL ShowMessageBoxMainThreadCallback(void *userdata)
            {
                i32 *hit_button = new i32(0);
                MessageBoxDataWithCallback *data = static_cast<MessageBoxDataWithCallback *>(userdata);
                SDL_MessageBoxData *mbdata = data->mbdata;
                bool show_mb_result = SDL_ShowMessageBox(mbdata, hit_button);
                const std::function<void(i32)> &function = data->function;
                delete data;
                if (!show_mb_result)
                {
                    throw Exception::SDLException(std::string("SDL couldn't show message box: ") + SDL_GetError(),
                                                  Logger::Severity::warning);
                }
                function(*hit_button);
            }

            void show_message_box(Logger::Severity severity, const std::string &title, const std::string &message,
                                  const std::vector<ButtonData> &buttons, const std::function<void(i32)> &callback)
            {
                // -- delete required --
                MessageBoxDataWithCallback *data =
                    new MessageBoxDataWithCallback(severity, title, message, buttons, callback);

                if (!SDL_RunOnMainThread(ShowMessageBoxMainThreadCallback, static_cast<void *>(data), false))
                {
                    throw Exception::SDLException(std::string("WindowsManager::show_message_box couldn't transfer "
                                                              "execution to the main thread: ") +
                                                      SDL_GetError(),
                                                  Logger::Severity::warning);
                }
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
                                         exit(-1);
                                     }
                                 });
            }

            void show_fatal_message_box(const std::string &message)
            {
                show_message_box(Logger::Severity::fatal, "Sola fatal", message, {ButtonData(0, true, true, "Quit")},
                                 [](i32) { exit(-1); });
            }

        } // namespace WindowsManager
    } // namespace Graphics
} // namespace Sola

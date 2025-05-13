#include "Graphics/WindowsManager.hpp"
#include "Application/Application.hpp"
#include "Exception/GeneralException.hpp"

namespace Sola
{
    namespace Graphics
    {
        namespace WindowsManager
        {
            /// @brief Little bit too much complicated class that simply stores the SDL message box data and the
            /// callback function. It is only used inside this C++ file to transfer the data from the show_message_box
            /// function to the main thread callback. **It should not** be used for anything else! Likewise, it is
            /// simply a temporary data holder.
            /// @attention Does allocate memory via "new" operator. The destructor should be properly called; otherwise
            /// there might be a chance for a memory leak.
            class MessageBoxDataWithCallback
            {
            public:
                /// @brief Constructor for the message box data. It initializes all the members of the structure.
                /// @param severity The severity level of the message box.
                /// @param title The title of the message box.
                /// @param message The message to be displayed in the message box.
                /// @param buttons A vector of button data for the message box.
                /// @param function A callback function to be called when a button is clicked.
                MessageBoxDataWithCallback(Logger::Severity severity, const std::string &title,
                                           const std::string &message, const std::vector<ButtonData> &buttons,
                                           const std::function<void(i32)> &function)
                    : function(function)
                {
                    // -- delete required --
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
                        case Logger::Severity::none:
                        case Logger::Severity::debug:
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

                /// @brief Copy constructor for the message box data is prohibited.
                MessageBoxDataWithCallback(const MessageBoxDataWithCallback &) = delete;

                /// @brief Normal move constructor
                /// @param other the other instance to move from.
                MessageBoxDataWithCallback(MessageBoxDataWithCallback &&other)
                    : function(std::move(other.function)), mbdata(std::exchange(other.mbdata, nullptr))
                {
                }

                /// @brief Simple destructor. Deletes the heap data allocated in the constructor
                /// @todo Why don't I use std::unique_ptr again?...
                ~MessageBoxDataWithCallback()
                {
                    delete[] mbdata->buttons;
                    delete mbdata;
                }

                /// @brief Move assignment operator for the MessageBoxDataWithCallback class.
                /// @param other the MessageBoxDataWithCallback object to move from.
                /// @return MessageBoxDataWithCallback& A reference to the current object
                /// after the assignment.
                MessageBoxDataWithCallback &operator=(MessageBoxDataWithCallback &&other)
                {
                    function = std::move(other.function);
                    mbdata = std::exchange(other.mbdata, nullptr);
                    return *this;
                }

                /// @brief The data directly used in SDL_ShowMessageBox
                SDL_MessageBoxData *mbdata;
                /// @brief The callback function
                std::function<void(int)> function;
            };

            /// @brief This function is called in the main thread by SDL to actually show the message box.
            /// @param userdata the pointer to the MessageBoxDataWithCallback object that contains all the data needed to show the
            /// message box.
            void SDLCALL ShowMessageBoxMainThreadCallback(void *userdata)
            {
                i32 *hit_button = new i32(-1);
                MessageBoxDataWithCallback *data = static_cast<MessageBoxDataWithCallback *>(userdata);
                SDL_MessageBoxData *mbdata = data->mbdata;
                bool show_mb_result = SDL_ShowMessageBox(mbdata, hit_button);
                if (!show_mb_result)
                {
                    print_warning("SDL_ShowMessageBox failed: " + std::string(SDL_GetError()));
                    *hit_button = -2;
                }
                data->function(*hit_button);
                delete data; // calling the MessageBoxDataWithCallback destructor and cleaning this manual memory
                             // control mess
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

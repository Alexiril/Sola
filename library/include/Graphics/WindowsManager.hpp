#ifndef SOLA_GRAPHICS_WINDOWSMANAGER
#define SOLA_GRAPHICS_WINDOWSMANAGER

#include "Logger/Severity.hpp"
#include "sola_common.hpp"

namespace Sola
{
    /// @brief This namespace contains all the graphics related code of the Sola library
    namespace Graphics
    {
        /// @brief This namespace contains all the code related to the WindowsManager. It is used to show message boxes,
        /// handle windows, etc.
        namespace WindowsManager
        {
            /// @brief Possible windows manager errors
            enum class WindowsManagerError
            {
                SHOW_MESSAGE_BOX_FAILED = 1,
            };

            /// @brief Contains basic button data to pass into show_message_box function. Does not support setting
            /// button position yet.
            /// @todo Check if SDL_ShowMessageBox does even support positioning those buttons or only allows choosing
            /// the direction of their appearance.
            /// @note Members is_escape_default and is_enter_default are used to identify which button should be
            /// considered as clicked when a user pushes the escape or enter button on their keyboard. button_id is the
            /// number of a hit button that will be passed into the callback function to determine what button was
            /// clicked.
            struct ButtonData
            {
            public:
                /// @brief Simple constructor for the button data. It initializes all the members of the structure.
                /// @param button_id the identifier for the button. It's passed into the callback function if the button
                /// is hit.
                /// @param is_escape_default if it is true, the button will be clicked automatically when a user pushes
                /// escape on their keyboard
                /// @param is_enter_default same as `is_escape_default`. If it's true, the button is clicked after
                /// pushing enter on a keyboard
                /// @param text the text shown on the button
                ButtonData(i32 button_id, bool is_escape_default, bool is_enter_default, const std::string &text)
                    : button_id(button_id), is_escape_default(is_escape_default), is_enter_default(is_enter_default),
                      text(text)
                {
                }

                /// @brief If it is true, the button will be clicked automatically when a user pushes
                /// escape on their keyboard
                bool is_escape_default;
                /// @brief If it is true, the button will be clicked automatically when a user pushes
                /// enter on their keyboard
                bool is_enter_default;
                /// @brief The identifier for the button. It's passed into the callback function if the button
                /// is hit.
                i32 button_id;
                /// @brief The text shown on the button
                std::string text;
            };

            /// @brief Calls SDL to show a message box with custom title, icon, text, and buttons.
            /// @param severity defines which icon will be shown in the message box. If severity is lower than info
            /// (none or debug) no icon is used. Error and fatal have the same icon.
            /// @param title text that will be shown (usually) on the top of the message box window.
            /// @param message text inside the message box window.
            /// @param buttons a list of ButtonData objects, containing all needed information to show the buttons.
            /// @param callback function that doesn't return anything and takes one integer (32 bits, usual int)
            /// argument. It will be called when a user clicks at any of the buttons or closes the window. The chosen
            /// button (or -1 if the window was closed) will be passed into the argument.
            /// @return Nothing if no error has happened or a WindowsManagerError if it was not possible to transfer
            /// execution to the main thread.
            /// @attention If any error happens when the execution is already in the main thread, trying to show the
            /// message box or handle the result if it is closed, no error or exception will be returned or raised
            /// anyway. The only change is the changed number of hit button. If the button was clicked, the argument
            /// will take the number of the button, if the window was closed then -1. And in the case of error, it will
            /// be -2. In addition, the function will log the error.
            /// @note This function does not (or may not) show the message box synchronously. It transfers the request
            /// to the main thread and does not wait for it to finish, preventing (likely not justifiably) deadlocks. If
            /// the function is called from the main thread, the execution will be synchronous.
            EXPORTED std::expected<void, WindowsManagerError>
            show_message_box(Logger::Severity severity, const std::string &title, const std::string &message,
                             const std::vector<ButtonData> &buttons, const std::function<void(i32)> &callback);

            /// @brief Simply calls show_message_box with some predefined values. The only button is "Ignore", and it
            /// doesn't do anything. Should be used to notify a user about some non-fatal exceptional events happening
            /// inside the code.
            /// @param message text to show inside the message box
            EXPORTED void show_warning_message_box(const std::string &message);
            /// @brief Calls show_message_box with predefined values. The buttons are "Ignore" and "Quit". When "Quit"
            /// button clicked, Sola::Exception::GeneralException is raised, trying to terminate the program if it was
            /// not intercepted and processed. It should be used as a less lethal version of show_fatal_message_box,
            /// when it is still possible to continue running the application without aborting.
            EXPORTED void show_error_message_box(const std::string &message);
            /// @brief Calls show_message_box with predefined values. The only button is "Quit", which throws
            /// Sola::Exception::GeneralException, trying to terminate the program. Although, it can be caught in some
            /// outer code (like in the application main function or something like it) to handle the exit process
            /// correctly.
            /// @param message text to show inside the message box
            /// @note Returns nothing. It's too late to return something, right? :)
            EXPORTED void show_fatal_message_box(const std::string &message);
        } // namespace WindowsManager
    } // namespace Graphics
} // namespace Sola

#endif

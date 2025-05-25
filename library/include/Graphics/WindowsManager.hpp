#ifndef GRAPHICS_WINDOWSMANAGER_HPP
#define GRAPHICS_WINDOWSMANAGER_HPP

#include "Logger/Severity.hpp"
#include "SolaCommon.hpp"

/// @brief This namespace contains all the code related to the WindowsManager. It is used to show message boxes,
/// handle windows, etc.
namespace Sola::Graphics::WindowsManager {
    /// @brief Possible windows manager errors
    enum class WindowsManagerError {
        ShowMessageBoxFailed,
    };

    /// @brief Contains basic button data to pass into showMessageBox function. Does not support setting
    /// button position yet.
    /// @todo Check if SDL_ShowMessageBox does even support positioning those buttons or only allows choosing
    /// the direction of their appearance.
    /// @note Members IsEscapeDefault and IsEnterDefault are used to identify which button should be
    /// considered as clicked when a user pushes the escape or enter button on their keyboard. ButtonID is the
    /// number of a hit button that will be passed into the callback function to determine what button was
    /// clicked.
    struct ButtonData {
    public:
        /// @brief Simple constructor for the button data. It initializes all the members of the structure.
        /// @param ButtonID the identifier for the button. It's passed into the callback function if the button
        /// is hit.
        /// @param IsEscapeDefault if it is true, the button will be clicked automatically when a user pushes
        /// escape on their keyboard
        /// @param IsEnterDefault same as `IsEscapeDefault`. If it's true, the button is clicked after
        /// pushing enter on a keyboard
        /// @param Text the Text shown on the button
        ButtonData(i32 ButtonID, bool IsEscapeDefault, bool IsEnterDefault, const std::string &Text)
            : ButtonID(ButtonID), IsEscapeDefault(IsEscapeDefault), IsEnterDefault(IsEnterDefault), Text(Text) {}

        /// @brief If it is true, the button will be clicked automatically when a user pushes
        /// escape on their keyboard
        bool IsEscapeDefault;
        /// @brief If it is true, the button will be clicked automatically when a user pushes
        /// enter on their keyboard
        bool IsEnterDefault;
        /// @brief The identifier for the button. It's passed into the callback function if the button
        /// is hit.
        i32 ButtonID;
        /// @brief The Text shown on the button
        std::string Text;
    };

    /// @brief Calls SDL to show a message box with custom Title, icon, Text, and buttons.
    /// @param Severity defines which icon will be shown in the message box. If Severity is lower than info
    /// (none or debug) no icon is used. Error and fatal have the same icon.
    /// @param Title Text that will be shown (usually) on the top of the message box window.
    /// @param Message Text inside the message box window.
    /// @param Buttons a list of ButtonData objects, containing all needed information to show the Buttons.
    /// @param Callback function that doesn't return anything and takes one integer (32 bits, usual int)
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
    EXPORTED auto showMessageBox(Logger::Severity Severity, const std::string &Title, const std::string &Message,
                                 const std::vector<ButtonData> &Buttons, const std::function<void(i32)> &Callback)
        -> std::expected<void, WindowsManagerError>;

    /// @brief Simply calls showMessageBox with some predefined values. The only button is "Ignore", and it
    /// doesn't do anything. Should be used to notify a user about some non-fatal exceptional events happening
    /// inside the code.
    /// @param Message Text to show inside the message box
    EXPORTED void showWarningMessageBox(const std::string &Message);
    /// @brief Calls showMessageBox with predefined values. The buttons are "Ignore" and "Quit". When "Quit"
    /// button clicked, Sola::Exception::GeneralException is raised, trying to terminate the program if it was
    /// not intercepted and processed. It should be used as a less lethal version of showFatalMessageBox,
    /// when it is still possible to continue running the application without aborting.
    /// @param Message Text to show inside the message box
    EXPORTED void showErrorMessageBox(const std::string &Message);
    /// @brief Calls showMessageBox with predefined values. The only button is "Quit", which throws
    /// Sola::Exception::GeneralException, trying to terminate the program. Although, it can be caught in some
    /// outer code (like in the application main function or something like it) to handle the exit process
    /// correctly.
    /// @param Message Text to show inside the message box
    /// @note Returns nothing. It's too late to return something, right? :)
    EXPORTED void showFatalMessageBox(const std::string &Message);
} // namespace Sola::Graphics::WindowsManager

#endif

#ifndef APPLICATION_MODULES_HPP
#define APPLICATION_MODULES_HPP

#include "SolaCommon.hpp"

namespace Sola::Application {
    /// @brief This is the enumeration for the possible modules that can be used in the application.
    enum class Module {
        Unknown,
        Audio,
        Video,
        Joystick,
        Haptic,
        Gamepad,
        Sensor,
        Camera,
    };

    /// @brief This little namespace contains useful functions to work with Module enumeration
    namespace ModuleFunctions {
        /// @brief Convert text to module enum (the text should be exactly one of the Module names, like 'Audio' =>
        /// `Module::Audio`).
        /// @param Text The text to convert. If the text is not one of the module names, `Module::Unknown` will be
        /// returned.
        /// @return The corresponding module enum.
        EXPORTED auto fromText(const std::string &Text) -> Module;
        /// @brief Convert module enum to text (returning exactly the value name, like `Module::Audio` => 'Audio').
        /// @param module The module enum to convert.
        /// @return The corresponding text.
        EXPORTED auto toText(Application::Module module) -> std::string;
    } // namespace ModuleFunctions
} // namespace Sola::Application

#endif

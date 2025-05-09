#ifndef SOLA_APPLICATION_MODULES
#define SOLA_APPLICATION_MODULES

#include "sola_common.hpp"

namespace Sola
{
    namespace Application
    {
        /// @brief This is the enumeration for the possible modules that can be used in the application.
        enum class EXPORTED Module
        {
            unknown,
            audio,
            video,
            joystick,
            haptic,
            gamepad,
            sensor,
            camera,
        };

        /// @brief This little namespace contains useful functions to work with Module enumeration
        namespace ModuleFunctions
        {
            /// @brief Convert text to module enum (the text should be exactly one of the Module names, like 'audio' =>
            /// `Module::audio`).
            /// @param text The text to convert. If the text is not one of the module names, `Module::unknown` will be
            /// returned.
            /// @return The corresponding module enum.
            EXPORTED Module from_text(const std::string &text);
            /// @brief Convert module enum to text (returning exactly the value name, like `Module::audio` => 'audio').
            /// @param module The module enum to convert.
            /// @return The corresponding text.
            EXPORTED std::string to_text(Module module);
        } // namespace ModuleFunctions
    } // namespace Application
} // namespace Sola

#endif

#ifndef SOLA_APPLICATION_MODULES
#define SOLA_APPLICATION_MODULES

#include "sola_common.hpp"

namespace Sola
{
    namespace Application
    {
        enum class EXPORTED Module
        {
            AUDIO,
            VIDEO,
            JOYSTICK,
            HAPTIC,
            GAMEPAD,
            EVENTS,
            SENSOR,
            CAMERA,
            UNKNOWN,
        };

        namespace ModuleFunctions
        {
            EXPORTED Module from_text(std::string text);
            EXPORTED std::string to_text(Module module);
            EXPORTED u32 to_sdlcode(Module module);
        } // namespace ModuleFunctions
    } // namespace Application
} // namespace Sola

#endif

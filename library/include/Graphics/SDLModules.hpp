#ifndef SOLA_GRAPHICS_SDLMODULES
#define SOLA_GRAPHICS_SDLMODULES

#include "sola_common.hpp"

namespace Sola
{
    namespace Graphics
    {
        enum class EXPORTED SDLModule
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

        namespace SDLModuleFunctions
        {
            EXPORTED SDLModule from_text(std::string text);
            EXPORTED std::string to_text(SDLModule module);
            EXPORTED u32 to_sdlcode(SDLModule module);
        } // namespace SDLModuleFunctions
    } // namespace Graphics
} // namespace Sola

#endif

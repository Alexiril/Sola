#include "Graphics/SDLModules.hpp"

namespace Sola
{
    namespace Graphics
    {
        namespace SDLModuleFunctions
        {
            SDLModule from_text(std::string text)
            {
                if (text == "AUDIO")
                {
                    return SDLModule::AUDIO;
                }
                else if (text == "VIDEO")
                {
                    return SDLModule::VIDEO;
                }
                else if (text == "JOYSTICK")
                {
                    return SDLModule::JOYSTICK;
                }
                else if (text == "HAPTIC")
                {
                    return SDLModule::HAPTIC;
                }
                else if (text == "GAMEPAD")
                {
                    return SDLModule::GAMEPAD;
                }
                else if (text == "EVENTS")
                {
                    return SDLModule::EVENTS;
                }
                else if (text == "SENSOR")
                {
                    return SDLModule::SENSOR;
                }
                else if (text == "CAMERA")
                {
                    return SDLModule::CAMERA;
                }

                return SDLModule::UNKNOWN;
            }

            std::string to_text(SDLModule module)
            {
                switch (module)
                {
                    case SDLModule::AUDIO:
                        return std::string("AUDIO");
                    case SDLModule::VIDEO:
                        return std::string("VIDEO");
                    case SDLModule::JOYSTICK:
                        return std::string("JOYSTICK");
                    case SDLModule::HAPTIC:
                        return std::string("HAPTIC");
                    case SDLModule::GAMEPAD:
                        return std::string("GAMEPAD");
                    case SDLModule::EVENTS:
                        return std::string("EVENTS");
                    case SDLModule::SENSOR:
                        return std::string("SENSOR");
                    case SDLModule::CAMERA:
                        return std::string("CAMERA");
                    case SDLModule::UNKNOWN:
                    default:
                        return "UNKNOWN";
                }
            }

            u32 to_sdlcode(SDLModule module)
            {
                switch (module)
                {
                    case SDLModule::AUDIO:
                        return SDL_INIT_AUDIO;
                    case SDLModule::VIDEO:
                        return SDL_INIT_VIDEO;
                    case SDLModule::JOYSTICK:
                        return SDL_INIT_JOYSTICK;
                    case SDLModule::HAPTIC:
                        return SDL_INIT_HAPTIC;
                    case SDLModule::GAMEPAD:
                        return SDL_INIT_GAMEPAD;
                    case SDLModule::EVENTS:
                        return SDL_INIT_EVENTS;
                    case SDLModule::SENSOR:
                        return SDL_INIT_SENSOR;
                    case SDLModule::CAMERA:
                        return SDL_INIT_CAMERA;
                    case SDLModule::UNKNOWN:
                    default:
                        return 0;
                }
            }
        } // namespace SDLModuleFunctions
    } // namespace Graphics
} // namespace Sola

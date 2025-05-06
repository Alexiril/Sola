#include "Application/Modules.hpp"

namespace Sola
{
    namespace Application
    {
        namespace ModuleFunctions
        {
            Module from_text(std::string text)
            {
                if (text == "AUDIO")
                {
                    return Module::AUDIO;
                }
                else if (text == "VIDEO")
                {
                    return Module::VIDEO;
                }
                else if (text == "JOYSTICK")
                {
                    return Module::JOYSTICK;
                }
                else if (text == "HAPTIC")
                {
                    return Module::HAPTIC;
                }
                else if (text == "GAMEPAD")
                {
                    return Module::GAMEPAD;
                }
                else if (text == "EVENTS")
                {
                    return Module::EVENTS;
                }
                else if (text == "SENSOR")
                {
                    return Module::SENSOR;
                }
                else if (text == "CAMERA")
                {
                    return Module::CAMERA;
                }

                return Module::UNKNOWN;
            }

            std::string to_text(Module module)
            {
                switch (module)
                {
                    case Module::AUDIO:
                        return std::string("AUDIO");
                    case Module::VIDEO:
                        return std::string("VIDEO");
                    case Module::JOYSTICK:
                        return std::string("JOYSTICK");
                    case Module::HAPTIC:
                        return std::string("HAPTIC");
                    case Module::GAMEPAD:
                        return std::string("GAMEPAD");
                    case Module::EVENTS:
                        return std::string("EVENTS");
                    case Module::SENSOR:
                        return std::string("SENSOR");
                    case Module::CAMERA:
                        return std::string("CAMERA");
                    case Module::UNKNOWN:
                    default:
                        return "UNKNOWN";
                }
            }

            u32 to_sdlcode(Module module)
            {
                switch (module)
                {
                    case Module::AUDIO:
                        return SDL_INIT_AUDIO;
                    case Module::VIDEO:
                        return SDL_INIT_VIDEO;
                    case Module::JOYSTICK:
                        return SDL_INIT_JOYSTICK;
                    case Module::HAPTIC:
                        return SDL_INIT_HAPTIC;
                    case Module::GAMEPAD:
                        return SDL_INIT_GAMEPAD;
                    case Module::EVENTS:
                        return SDL_INIT_EVENTS;
                    case Module::SENSOR:
                        return SDL_INIT_SENSOR;
                    case Module::CAMERA:
                        return SDL_INIT_CAMERA;
                    case Module::UNKNOWN:
                    default:
                        return 0;
                }
            }
        } // namespace ModuleFunctions
    } // namespace Application
} // namespace Sola

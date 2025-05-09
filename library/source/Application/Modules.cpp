#include "Application/Modules.hpp"

namespace Sola
{
    namespace Application
    {
        namespace ModuleFunctions
        {
            Module from_text(const std::string &text)
            {
                if (text == "audio")
                {
                    return Module::audio;
                }
                else if (text == "video")
                {
                    return Module::video;
                }
                else if (text == "joystick")
                {
                    return Module::joystick;
                }
                else if (text == "haptic")
                {
                    return Module::haptic;
                }
                else if (text == "gamepad")
                {
                    return Module::gamepad;
                }
                else if (text == "sensor")
                {
                    return Module::sensor;
                }
                else if (text == "camera")
                {
                    return Module::camera;
                }

                return Module::unknown;
            }

            std::string to_text(Module module)
            {
                switch (module)
                {
                    case Module::audio:
                        return std::string("audio");
                    case Module::video:
                        return std::string("video");
                    case Module::joystick:
                        return std::string("joystick");
                    case Module::haptic:
                        return std::string("haptic");
                    case Module::gamepad:
                        return std::string("gamepad");
                    case Module::sensor:
                        return std::string("sensor");
                    case Module::camera:
                        return std::string("camera");
                    case Module::unknown:
                    default:
                        return "unknown";
                }
            }
        } // namespace ModuleFunctions
    } // namespace Application
} // namespace Sola

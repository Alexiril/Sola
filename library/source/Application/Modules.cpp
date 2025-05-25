#include "Application/Modules.hpp"

namespace Sola::Application::ModuleFunctions {
    auto fromText(const std::string &Text) -> Application::Module {
        if (Text == "audio") {
            return Application::Module::Audio;
        }
        if (Text == "video") {
            return Application::Module::Video;
        }
        if (Text == "joystick") {
            return Application::Module::Joystick;
        }
        if (Text == "haptic") {
            return Application::Module::Haptic;
        }
        if (Text == "gamepad") {
            return Application::Module::Gamepad;
        }
        if (Text == "sensor") {
            return Application::Module::Sensor;
        }
        if (Text == "camera") {
            return Application::Module::Camera;
        }

        return Application::Module::Unknown;
    }

    auto toText(Application::Module Module) -> std::string {
        switch (Module) {
            case Application::Module::Audio:
                return {"Audio"};
            case Application::Module::Video:
                return {"Video"};
            case Application::Module::Joystick:
                return {"Joystick"};
            case Application::Module::Haptic:
                return {"Haptic"};
            case Application::Module::Gamepad:
                return {"Gamepad"};
            case Application::Module::Sensor:
                return {"Sensor"};
            case Application::Module::Camera:
                return {"Camera"};
            case Application::Module::Unknown:
                [[fallthrough]];
            default:
                return {"Unknown"};
        }
    }
} // namespace Sola::Application::ModuleFunctions

#ifndef SOLA_GRAPHICS_WINDOWSMANAGER
#define SOLA_GRAPHICS_WINDOWSMANAGER

#include "Logger/Severity.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Graphics
    {
        namespace WindowsManager
        {
            struct ButtonData
            {
            public:
                ButtonData(i32 button_id, bool is_escape_default, bool is_enter_default, const std::string &text)
                    : button_id(button_id), is_escape_default(is_escape_default), is_enter_default(is_enter_default),
                      text(text)
                {
                }

                bool is_escape_default;
                bool is_enter_default;
                i32 button_id;
                std::string text;
            };

            EXPORTED void show_message_box(Logger::Severity severity, const std::string &title,
                                           const std::string &message, const std::vector<ButtonData> &buttons,
                                           const std::function<void(i32)> &callback);

            EXPORTED void show_warning_message_box(const std::string &message);
            EXPORTED void show_error_message_box(const std::string &message);
            EXPORTED void show_fatal_message_box(const std::string &message);
        } // namespace WindowsManager
    } // namespace Graphics
} // namespace Sola

#endif

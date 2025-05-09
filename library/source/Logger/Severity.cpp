#include "Logger/Severity.hpp"

namespace Sola
{
    namespace Logger
    {
        namespace SeverityFunctions
        {
            Severity from_text(const std::string &text)
            {
                if (text == "none")
                {
                    return Severity::none;
                }
                if (text == "debug")
                {
                    return Severity::debug;
                }
                if (text == "info")
                {
                    return Severity::info;
                }
                if (text == "warning")
                {
                    return Severity::warning;
                }
                if (text == "error")
                {
                    return Severity::error;
                }
                if (text == "fatal")
                {
                    return Severity::fatal;
                }
                return Severity::none;
            }

            std::string to_text(Severity severity)
            {
                switch (severity)
                {
                    case Severity::none:
                        return std::string("none");
                    case Severity::debug:
                        return std::string("debug");
                    case Severity::info:
                        return std::string("info");
                    case Severity::warning:
                        return std::string("warning");
                    case Severity::error:
                        return std::string("error");
                    case Severity::fatal:
                        return std::string("fatal");
                    default:
                        return "info";
                }
            }

        } // namespace SeverityFunctions
    } // namespace Logger
} // namespace Sola

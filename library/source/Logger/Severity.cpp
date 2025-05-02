#include "Logger/Severity.hpp"

namespace Sola
{
    namespace Logger
    {
        std::string Logger::severity_to_text(Severity severity)
        {
            switch (severity)
            {
                case Severity::debug:
                    return std::string("DEBUG");
                case Severity::info:
                    return std::string("INFO");
                case Severity::warning:
                    return std::string("WARNING");
                case Severity::error:
                    return std::string("ERROR");
                case Severity::fatal:
                    return std::string("FATAL");
                default:
                    return "LOG";
            }
        }

    } // namespace Logger
} // namespace Sola

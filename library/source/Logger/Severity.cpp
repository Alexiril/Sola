#include "Logger/Severity.hpp"

namespace Sola::Logger::SeverityFunctions {
    auto fromText(const std::string &Text) -> Severity {
        if (Text == "None") {
            return Severity::None;
        }
        if (Text == "Debug") {
            return Severity::Debug;
        }
        if (Text == "Info") {
            return Severity::Info;
        }
        if (Text == "Warning") {
            return Severity::Warning;
        }
        if (Text == "Error") {
            return Severity::Error;
        }
        if (Text == "Fatal") {
            return Severity::Fatal;
        }
        return Severity::None;
    }

    auto toText(Logger::Severity severity) -> std::string {
        switch (severity) {
            case Logger::Severity::None:
                return std::string("None");
            case Logger::Severity::Debug:
                return std::string("Debug");
            case Logger::Severity::Info:
                return std::string("Info");
            case Logger::Severity::Warning:
                return std::string("Warning");
            case Logger::Severity::Error:
                return std::string("Error");
            case Logger::Severity::Fatal:
                return std::string("Fatal");
            default:
                return "Info";
        }
    }

} // namespace Sola::Logger::SeverityFunctions

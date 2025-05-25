#include "Logger/Logger.hpp"

namespace Sola::Logger {
    static std::mutex OutputMutex;

    void printLog(const std::string &File, u64 Line, const std::string &What, Logger::Severity Severity) {
        std::ostringstream Output;

        Output << SeverityFunctions::toText(Severity) << " [" << File << " : " << Line << "]\n" << What;

        std::lock_guard<std::mutex> Lock(OutputMutex); // It's released when functions ends
        switch (Severity) {
            case Logger::Severity::None:
                // No logging
                break;
            case Logger::Severity::Debug:
#ifdef SOLA_DEBUG_LOG
                std::cout << "\033[90m" << Output.str() << "\033[0m" << '\n';
#endif
                break;
            case Logger::Severity::Info:
                std::cout << "\033[37m" << Output.str() << "\033[0m" << '\n';
                break;
            case Logger::Severity::Warning:
                std::cerr << "\033[93m" << Output.str() << "\033[0m" << '\n';
                break;
            case Logger::Severity::Error:
                std::cerr << "\033[91m" << Output.str() << "\033[0m" << '\n';
                break;
            case Logger::Severity::Fatal:
                std::cerr << "\033[95m" << Output.str() << "\033[0m" << '\n';
                break;
            default:
                break;
        }
    }

} // namespace Sola::Logger

#include "Logger/Logger.hpp"

namespace Sola
{
    namespace Logger
    {
        static std::mutex output_mutex;

        void print_log(const std::string &file, u64 line, const std::string &what,
                       Severity severity)
        {
            std::ostringstream output;

            output << severity_to_text(severity) << " [" << file << " : " << line
                   << "]\n"
                   << what;

            std::lock_guard<std::mutex> lock(
                output_mutex); // It's released when functions ends
            switch (severity)
            {
                case Severity::debug:
#ifdef SOLA_DEBUG_LOG
                    std::cout << "\033[90m" << output.str() << "\033[0m" << std::endl;
#endif
                    break;
                case Severity::info:
                    std::cout << "\033[37m" << output.str() << "\033[0m" << std::endl;
                    break;
                case Severity::warning:
                    std::cerr << "\033[93m" << output.str() << "\033[0m" << std::endl;
                    break;
                case Severity::error:
                    std::cerr << "\033[91m" << output.str() << "\033[0m" << std::endl;
                    break;
                case Severity::fatal:
                    std::cerr << "\033[95m" << output.str() << "\033[0m" << std::endl;
                    break;
                default:
                    break;
            }
        }

    } // namespace Logger
} // namespace Sola

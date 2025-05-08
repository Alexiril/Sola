#ifndef SOLA_EXCEPTION_GENERAL_EXCEPTION
#define SOLA_EXCEPTION_GENERAL_EXCEPTION

#include "sola_common.hpp"

#include "Logger/Logger.hpp"

namespace Sola
{
    namespace Exception
    {
        class BasicException : public std::runtime_error
        {
        public:
            explicit BasicException(const char *filename, u64 line, const char *what, Logger::Severity severity)
                : BasicException(std::string(filename), line, std::string(what), severity)
            {
            }

            explicit BasicException(const std::string &filename, u64 line, const std::string &what,
                                    Logger::Severity severity)
                : std::runtime_error(what.c_str()), severity(severity)
            {
                Logger::print_log(filename, line, what, severity);
            }

            const Logger::Severity severity;
        };
    } // namespace Exception
} // namespace Sola

#define SOLA_GENERAL_EXCEPTION(what, severity) Sola::Exception::BasicException(__FILE__, __LINE__, what, severity)

#endif

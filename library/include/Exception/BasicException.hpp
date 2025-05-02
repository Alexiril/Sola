#ifndef SOLA_EXCEPTION_BASIC_EXCEPTION
#define SOLA_EXCEPTION_BASIC_EXCEPTION

#include "sola_common.hpp"

#include "Logger/Logger.hpp"

namespace Sola
{
    namespace Exception
    {
        class BasicException : public std::runtime_error
        {
        public:
            explicit BasicException(const char *what, Logger::Severity severity)
                : BasicException(std::string(what), severity)
            {
            }

            explicit BasicException(const std::string &what, Logger::Severity severity)
                : std::runtime_error(what.c_str()), severity(severity)
            {
                print(what, severity);
            }

            Logger::Severity get_severity(void) const noexcept { return severity; }

        private:
            Logger::Severity severity;
        };
    } // namespace Exception
} // namespace Sola

#endif

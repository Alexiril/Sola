#ifndef SOLA_LOGGER_SEVERITY
#define SOLA_LOGGER_SEVERITY

#include "sola_common.hpp"

namespace Sola
{

    namespace Logger
    {
        enum class EXPORTED Severity
        {
            debug,
            info,
            warning,
            error,
            fatal
        };

        namespace SeverityFunctions
        {
            EXPORTED Severity from_text(const std::string &text);
            EXPORTED std::string to_text(Severity severity);
        } // namespace SeverityFunctions
    } // namespace Logger
} // namespace Sola

#endif

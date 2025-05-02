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

        EXPORTED std::string severity_to_text(Severity severity);
    } // namespace Logger
} // namespace Sola

#endif

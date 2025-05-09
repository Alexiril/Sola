#ifndef SOLA_LOGGER_SEVERITY
#define SOLA_LOGGER_SEVERITY

#include "sola_common.hpp"

namespace Sola
{

    namespace Logger
    {
        /// @brief Severity levels for logging messages.
        /// @details The severity levels are used to categorize the log messages
        /// based on their importance. The levels are ordered from the least important to the most important.
        /// @note The `none` level is used to disable logging.
        /// @note `debug` is logged only if SOLA_DEBUG_LOG macro was defined
        /// during the library build process.
        enum class EXPORTED Severity : u8
        {
            none,    ///< No logging.
            debug,   ///< Debug level logging.
            info,    ///< Informational level logging.
            warning, ///< Warning level logging.
            error,   ///< Error level logging.
            fatal    ///< Fatal level logging.
        };

        /// @brief This namespace contains all the functions related to the severity levels.
        namespace SeverityFunctions
        {
            /// @brief Convert text to severity level (the text should be exactly one of the severity names, like
            /// 'debug' => `Severity::debug`).
            /// @param text The text to convert. If the text is not one of the severity names, `Severity::none` will be
            /// returned.
            /// @return The corresponding severity level.
            EXPORTED Severity from_text(const std::string &text);
            /// @brief Convert severity level to text (the resulting text will be exactly the same as the name of the
            /// enumeration option, like `Severity::debug` => 'debug').
            /// @param severity The severity level to convert.
            /// @return The corresponding text.
            EXPORTED std::string to_text(Severity severity);
        } // namespace SeverityFunctions
    } // namespace Logger
} // namespace Sola

#endif

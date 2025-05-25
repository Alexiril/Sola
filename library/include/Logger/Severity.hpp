#ifndef LOGGER_SEVERITY_HPP
#define LOGGER_SEVERITY_HPP

#include "SolaCommon.hpp"

namespace Sola::Logger {
    /// @brief Severity levels for logging messages.
    /// @details The severity levels are used to categorize the log messages
    /// based on their importance. The levels are ordered from the least important to the most important.
    /// @note The `None` level is used to disable logging.
    /// @note `Debug` is logged only if SOLA_DEBUG_LOG macro was defined
    /// during the library build process.
    enum class Severity : u8 { None, Debug, Info, Warning, Error, Fatal };

    /// @brief This namespace contains all the functions related to the severity levels.
    namespace SeverityFunctions {
        /// @brief Convert text to severity level (the text should be exactly one of the severity names, like
        /// 'Debug' => `Severity::Debug`).
        /// @param Text the text to convert. If the text is not one of the severity names, `Severity::None` will be
        /// returned.
        /// @return The corresponding severity level.
        EXPORTED auto fromText(const std::string &Text) -> Severity;
        /// @brief Convert severity level to text (the resulting text will be exactly the same as the name of the
        /// enumeration option, like `Severity::Debug` => 'Debug').
        /// @param Severity The severity level to convert.
        /// @return The corresponding text.
        EXPORTED auto toText(Logger::Severity Severity) -> std::string;
    } // namespace SeverityFunctions
} // namespace Sola::Logger

#endif

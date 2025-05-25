#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include "Logger/Severity.hpp"
#include "SolaCommon.hpp"

/// @brief This namespace contains all the logging related code of the Sola library
namespace Sola::Logger {
    /// @brief This functions writes the text into the log. It is used to log all the messages from the Sola
    /// library. Also, it's recommended to use print macros instead of this function directly.
    /// @param File the name of the file from where this function was called
    /// @param Line the line number from where this function was called
    /// @param What the text to be logged
    /// @param Severity the severity of the message. It can be one of the following: None, Debug, Info,
    /// Warning, Error, Fatal.
    /// @note The function uses the mutex to protect the output stream from concurrent access.
    /// @note If the severity is None, no actual logging is done.
    /// @attention This function uses std::cout and std::cerr, which may be not the best choice. This fact really
    /// needs rethinking about it again. It was done only for debug purposes.
    /// @todo This function should be reimplemented to use the logging library (like spdlog or something like that)
    /// or at least it should print into a real customizable file.
    EXPORTED void printLog(const std::string &File, u64 Line, const std::string &What, Logger::Severity Severity);
} // namespace Sola::Logger

#define print(What, SeverityValue) Sola::Logger::printLog(__FILE__, __LINE__, What, SeverityValue)
#define printDebug(What)           print(What, Sola::Logger::Severity::Debug)
#define printInfo(What)            print(What, Sola::Logger::Severity::Info)
#define printWarning(What)         print(What, Sola::Logger::Severity::Warning)
#define printError(What)           print(What, Sola::Logger::Severity::Error)
#define printFatal(What)           print(What, Sola::Logger::Severity::Fatal)

#endif

#ifndef SOLA_LOGGER_LOGGER
#define SOLA_LOGGER_LOGGER

#include "Logger/Severity.hpp"
#include "sola_common.hpp"

namespace Sola
{

    /// @brief This namespace contains all the logging related code of the Sola library
    namespace Logger
    {
        /// @brief This functions writes the text into the log. It is used to log all the messages from the Sola
        /// library. Also, it's recommended to use print macros instead of this function directly.
        /// @param file the name of the file from where this function was called
        /// @param line the line number from where this function was called
        /// @param what the text to be logged
        /// @param severity the severity of the message. It can be one of the following: none, debug, info, warning,
        /// error, fatal.
        /// @note The function uses the mutex to protect the output stream from concurrent access.
        /// @note If the severity is none, no actual logging is done.
        /// @attention This function uses std::cout and std::cerr, which may be not the best choice. This fact really
        /// needs rethinking about it again. It was done only for debug purposes.
        /// @todo This function should be reimplemented to use the logging library (like spdlog or something like that)
        /// or at least it should print into a real customizable file.
        EXPORTED void print_log(const std::string &file, u64 line, const std::string &what, Severity severity);
    } // namespace Logger
} // namespace Sola

#define print(what, severity) Sola::Logger::print_log(__FILE__, __LINE__, what, severity)
#define print_debug(what)     print(what, Sola::Logger::Severity::debug)
#define print_info(what)      print(what, Sola::Logger::Severity::info)
#define print_warning(what)   print(what, Sola::Logger::Severity::warning)
#define print_error(what)     print(what, Sola::Logger::Severity::error)
#define print_fatal(what)     print(what, Sola::Logger::Severity::fatal)

#endif

#ifndef SOLA_EXCEPTION_GENERAL_EXCEPTION
#define SOLA_EXCEPTION_GENERAL_EXCEPTION

#include "sola_common.hpp"

#include "Logger/Logger.hpp"

namespace Sola
{
    /// @brief This namespace contains Sola exceptions
    /// @attention Sola **does not** use any exceptions in a normal case. Catching those exceptions is considered to be
    /// **very slow** comparing to no-exception case. We do not prohibit C++ standard exceptions explicitly (like with
    /// the compiler flags), but you should always consider using a different, faster approach (like std::expected or
    /// std::optional) if possible. In general, Sola uses exceptions **only** if something outstanding, really severe
    /// happened, if the time that it takes to handle this exception is not relevant anymore, like serious crash, like
    /// not enough memory error, etc. When the application needs to stop anyway to handle this.
    namespace Exception
    {
        /// @brief This class is used as the basic printable (to log) exception. It should only be used if you expect
        /// the program to most likely stop. Based on std::runtime_error
        /// @note To throw or create it use SOLA_GENERAL_EXCEPTION(what, severity) macro.
        class GeneralException : public std::runtime_error
        {
        public:
            /// @brief The general exception constructor for constant character pointer (C-string), simply transfers
            /// params into std::string constructor.
            /// @param filename the name of the source (C++) file from where this exception was raised
            /// @param line the line in the source, where the exception was raised
            /// @param what text of the actual exception passed into std::runtime_error
            /// @param severity level of the exception. In the idea, it should always be fatal inside this library. But
            /// any severity value is possible.
            /// @note Do not use it without the SOLA_GENERAL_EXCEPTION macro. It does save the filename and line
            /// correctly, while it is pretty hard to do it without a macro :)
            explicit GeneralException(const char *filename, u64 line, const char *what, Logger::Severity severity)
                : GeneralException(std::string(filename), line, std::string(what), severity)
            {
            }

            /// @brief The general exception constructor for std::string. Passes the data into std::runtime_error and
            /// prints the error to log, using filename, line, the text, and severity
            /// @param filename the name of the source (C++) file from where this exception was raised
            /// @param line the line in the source, where the exception was raised
            /// @param what text of the actual exception passed into std::runtime_error
            /// @param severity level of the exception. In the idea, it should always be fatal inside this library. But
            /// any severity value is possible.
            /// @note Do not use it without the SOLA_GENERAL_EXCEPTION macro. It does save the filename and line
            /// correctly, while it is hard to achieve something similar without a macro.
            explicit GeneralException(const std::string &filename, u64 line, const std::string &what,
                                      Logger::Severity severity)
                : std::runtime_error(what.c_str()), severity(severity)
            {
                Logger::print_log(filename, line, what, severity);
            }

            /**
             * @brief Represents the severity level of an exception and a log message printed when the exception is
             * raised.
             */
            const Logger::Severity severity;
        };
    } // namespace Exception
} // namespace Sola

#define SOLA_GENERAL_EXCEPTION(what, severity) Sola::Exception::GeneralException(__FILE__, __LINE__, what, severity)

#endif

#ifndef EXCEPTIONS_GENERAL_EXCEPTION_HPP
#define EXCEPTIONS_GENERAL_EXCEPTION_HPP

#include "SolaCommon.hpp"

#include "Logger/Logger.hpp"

namespace Sola::Exceptions {
    /// @brief This class is used as the basic printable (to log) exception. It should only be used if you expect
    /// the program to most likely stop. Based on std::runtime_error
    /// @note To throw or create it use SOLA_GENERAL_EXCEPTION(what, severity) macro.
    class GeneralException : public std::runtime_error {
    public:
        /// @brief The general exception constructor for constant character pointer (C-string), simply transfers
        /// params into std::string constructor.
        /// @param FileName the name of the source (C++) file from where this exception was raised
        /// @param Line the line in the source, where the exception was raised
        /// @param What text of the actual exception passed into std::runtime_error
        /// @param Severity level of the exception. In the idea, it should always be fatal inside this library. But
        /// any severity value is possible.
        /// @note Do not use it without the SOLA_GENERAL_EXCEPTION macro. It does save the filename and line
        /// correctly, while it is pretty hard to do it without a macro :)
        explicit GeneralException(const char *FileName, u64 Line, const char *What, Logger::Severity Severity)
            : GeneralException(std::string(FileName), Line, std::string(What), Severity) {}

        /// @brief The general exception constructor for std::string. Passes the data into std::runtime_error and
        /// prints the error to log, using filename, line, the text, and severity
        /// @param FileName the name of the source (C++) file from where this exception was raised
        /// @param Line the line in the source, where the exception was raised
        /// @param What text of the actual exception passed into std::runtime_error
        /// @param Severity level of the exception. In the idea, it should always be fatal inside this library. But
        /// any severity value is possible.
        /// @note Do not use it without the SOLA_GENERAL_EXCEPTION macro. It does save the filename and line
        /// correctly, while it is hard to achieve something similar without a macro.
        explicit GeneralException(const std::string &FileName, u64 Line, const std::string &What,
                                  Logger::Severity Severity)
            : std::runtime_error(What.c_str()), Severity(Severity) {
            Logger::printLog(FileName, Line, What, Severity);
        }

        /**
         * @brief Represents the Severity level of an exception and a log message printed when the exception is
         * raised.
         */
        const Logger::Severity Severity;
    };
} // namespace Sola::Exceptions

#define SOLA_GENERAL_EXCEPTION(What, Severity) Sola::Exceptions::GeneralException(__FILE__, __LINE__, What, Severity)

#endif

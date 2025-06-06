#ifndef EDITOR_INITIALIZER_INITIALIZER_HPP
#define EDITOR_INITIALIZER_INITIALIZER_HPP

#include "SolaCommon.hpp"

namespace Sola::Runtime::Editor {

    /// @brief This enum class defines the possible errors that can occur during the initialization of the editor
    /// application.
    enum class InitializerError {
        InvalidArguments,
        InitializationFailed,
        ProjectNotFound,
        UnsupportedVersion,
        UnknownError
    };

    /// @brief This class is used to initialize the editor application.
    class InitializerType {
    public:
        /// @brief Initializes the editor application.
        /// @param ArgumentsCount The number of command line arguments.
        /// @param Arguments The command line arguments.
        /// @return An expected void on success, or an error code on failure.
        static auto initializeApplication(i32 ArgumentsCount, char **Arguments)
            -> std::expected<void, InitializerError>;

        /// @brief Converts an initializer error to a string.
        /// @param error The error to convert.
        /// @return The string representation of the error.
        static auto toString(InitializerError error) -> std::string;
    };
} // namespace Sola::Runtime::Editor

#endif // EDITOR_INITIALIZER_INITIALIZER_HPP

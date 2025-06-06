#ifndef INITIALIZER_INITIALIZER_HPP
#define INITIALIZER_INITIALIZER_HPP

namespace Sola::Runtime {
    /// @brief This enum class defines the possible errors that can occur during the initialization of the actual
    /// application.
    enum class InitializerError { InitializationFailed, UnknownError };

    /// @brief This class is used to initialize the actual user application.
    class InitializerType {
    public:
        // NOLINTBEGIN(readability-named-parameter): Is not implemented yet, so no need to follow the naming convention.

        /// @brief Initializes the application.
        /// @return An expected void on success, or an error code on failure.
        static std::expected<void, InitializerError> initializeApplication(i32, char **) {
            std::string ProjectPath =
                (Sola::Helpers::FileSystem::getExecutableDirectory().value_or("") / "data").string();
            // This is a placeholder implementation.
            return std::unexpected(InitializerError::UnknownError);
        }

        // NOLINTEND(readability-named-parameter)

        /// @brief Converts an initializer error to a string.
        /// @param error The error to convert.
        /// @return The string representation of the error.
        static auto toString(InitializerError error) -> std::string {
            switch (error) {
                case InitializerError::InitializationFailed:
                    return "Application initialization failed.";
                case InitializerError::UnknownError:
                    [[fallthrough]];
                default:
                    return "An unknown error occurred during application initialization.";
            }
        }
    };
} // namespace Sola::Runtime

#endif // INITIALIZER_INITIALIZER_HPP

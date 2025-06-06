#ifndef FINALIZER_FINALIZER_HPP
#define FINALIZER_FINALIZER_HPP

namespace Sola::Runtime {
    /// @brief This enum class defines the possible errors that can occur during the finalization of the actual
    /// application.
    enum class FinalizerError { FinalizationFailed, UnknownError };

    /// @brief This class is used to finalize the actual user application.
    class FinalizerType {
    public:
        // NOLINTBEGIN(readability-named-parameter): Is not implemented yet, so no need to follow the naming convention.

        /// @brief Finalizes the application.
        /// @return An expected void on success, or an error code on failure.
        static std::expected<void, FinalizerError> finalizeApplication() {
            // This is a placeholder implementation.
            return std::unexpected(FinalizerError::UnknownError);
        }

        // NOLINTEND(readability-named-parameter)

        /// @brief Converts a finalizer error to a string.
        /// @param error The error to convert.
        /// @return The string representation of the error.
        static auto toString(FinalizerError error) -> std::string {
            switch (error) {
                case FinalizerError::FinalizationFailed:
                    return "Application finalization failed.";
                case FinalizerError::UnknownError:
                    [[fallthrough]];
                default:
                    return "An unknown error occurred during application finalization.";
            }
        }
    };
} // namespace Sola::Runtime

#endif // FINALIZER_FINALIZER_HPP
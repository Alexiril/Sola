#ifndef EDITOR_FINALIZER_FINALIZER_HPP
#define EDITOR_FINALIZER_FINALIZER_HPP

#include "SolaCommon.hpp"

namespace Sola::Runtime::Editor {

    /// @brief This enum class defines the possible errors that can occur during the finalization of the editor
    /// application.
    enum class FinalizerError {
        FinalizationFailed,
        UnknownError
    };

    /// @brief This class is used to finalize the editor application.
    class FinalizerType {
    public:
        /// @brief Finalizes the editor application.
        /// @return An expected void on success, or an error code on failure.
        static auto finalizeApplication() -> std::expected<void, FinalizerError>;

        /// @brief Converts a finalizer error to a string.
        /// @param error The error to convert.
        /// @return The string representation of the error.
        static auto toString(FinalizerError error) -> std::string;
    };
} // namespace Sola::Runtime::Editor

#endif // EDITOR_FINALIZER_FINALIZER_HPP

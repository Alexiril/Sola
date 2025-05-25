#ifndef HELPERS_FILESYSTEM_HPP
#define HELPERS_FILESYSTEM_HPP

#include "SolaCommon.hpp"

namespace Sola::Helpers {
    /// @brief This namespace contains all the helper functions related to the file system.
    namespace FileSystem {
        /// @brief Possible errors that can occur in the file system functions.
        enum class FileSystemError {
            ExecutableDirectoryUnavailable,
        };

        /// @brief Get the directory where the executable is located.
        /// @return The path to the executable directory or an error code if it couldn't get it.
        EXPORTED auto getExecutableDirectory() -> std::expected<std::filesystem::path, FileSystemError>;
    } // namespace FileSystem
} // namespace Sola::Helpers

#endif

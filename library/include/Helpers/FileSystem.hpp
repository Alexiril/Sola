#ifndef SOLA_HELPERS_FILESYSTEM
#define SOLA_HELPERS_FILESYSTEM

#include "sola_common.hpp"

namespace Sola
{
    /// @brief This namespace contains all the helper functions that are not related to any specific module.
    namespace Helpers
    {
        /// @brief This namespace contains all the helper functions related to the file system.
        namespace FileSystem
        {
            /// @brief Possible errors that can occur in the file system functions.
            enum class FileSystemError
            {
                ExecutableDirectoryUnavailable,
            };

            /// @brief Get the directory where the executable is located.
            /// @return The path to the executable directory or an error code if it couldn't get it.
            EXPORTED std::expected<std::filesystem::path, FileSystemError> get_executable_directory(void);
        } // namespace FileSystem
    } // namespace Helpers
} // namespace Sola

#endif

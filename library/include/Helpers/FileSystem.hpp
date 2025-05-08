#ifndef SOLA_HELPERS_FILESYSTEM
#define SOLA_HELPERS_FILESYSTEM

#include "sola_common.hpp"

namespace Sola
{
    namespace Helpers
    {
        namespace FileSystem
        {
            enum class FileSystemError
            {
                ExecutableDirectoryUnavailable,
            };

            EXPORTED std::expected<std::filesystem::path, FileSystemError> get_executable_directory(void);
        } // namespace FileSystem
    } // namespace Helpers
} // namespace Sola

#endif

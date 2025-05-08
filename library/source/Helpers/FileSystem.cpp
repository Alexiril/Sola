#include "Helpers/FileSystem.hpp"
#include "Logger/Logger.hpp"

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    include <Windows.h>
#elif __APPLE__
#    include <climits>
#    include <mach-o/dyld.h>
#else
#    include <unistd.h>
#endif

namespace Sola
{
    namespace Helpers
    {
        namespace FileSystem
        {
            std::expected<std::filesystem::path, FileSystemError> Sola::Helpers::FileSystem::get_executable_directory()
            {
#ifdef _WIN32
                wchar_t szPath[MAX_PATH];
                if (GetModuleFileNameW(nullptr, szPath, MAX_PATH) == 0)
                {
                    print_warning("GetModuleFileNameW failed with error code: " + std::to_string(GetLastError()));
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
#elif __APPLE__
                char szPath[PATH_MAX];
                uint32_t bufsize = PATH_MAX;
                if (_NSGetExecutablePath(szPath, &bufsize))
                {
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
#else
                char szPath[PATH_MAX];
                ssize_t count = readlink("/proc/self/exe", szPath, PATH_MAX);
                if (count < 0 || count >= PATH_MAX)
                {
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
                szPath[count] = '\0';
#endif
                return std::filesystem::path{szPath}.parent_path() / "";
            }
        } // namespace FileSystem
    } // namespace Helpers
} // namespace Sola

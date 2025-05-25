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

namespace Sola::Helpers::FileSystem {
    auto Sola::Helpers::FileSystem::getExecutableDirectory() -> std::expected<std::filesystem::path, FileSystemError> {
#ifdef _WIN32
                std::array<wchar_t, MAX_PATH> SzPath;
                if (GetModuleFileNameW(nullptr, SzPath.data(), MAX_PATH) == 0) {
                    printWarning("GetModuleFileNameW failed with error code: " + std::to_string(GetLastError()));
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
#elif __APPLE__
                std::array<char, PATH_MAX> SzPath;
                uint32_t bufsize = PATH_MAX;
                if (_NSGetExecutablePath(SzPath.data(), &bufsize)) {
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
#else
                std::array<char, PATH_MAX> SzPath;
                ssize_t count = readlink("/proc/self/exe", SzPath.data(), PATH_MAX);
                if (count < 0 || count >= PATH_MAX) {
                    return std::unexpected<FileSystemError>(FileSystemError::ExecutableDirectoryUnavailable);
                }
                SzPath[count] = '\0';
#endif
                return std::filesystem::path{SzPath.data()}.parent_path() / "";
    }
} // namespace Sola::Helpers::FileSystem

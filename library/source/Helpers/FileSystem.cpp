#include "Helpers/FileSystem.hpp"
#include "Exception/FileSystemException.hpp"

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    include <Windows.h>
#elif __APPLE__
#    include <climits>
#    include <mach-o/dyld.h>
#elif
#    include <unistd.h>
#endif

namespace Sola
{
    namespace Helpers
    {
        namespace FileSystem
        {
            std::filesystem::path Sola::Helpers::FileSystem::get_executable_directory()
            {
#ifdef _WIN32
                wchar_t szPath[MAX_PATH];
                GetModuleFileNameW(nullptr, szPath, MAX_PATH);
#elif __APPLE__
                char szPath[PATH_MAX];
                uint32_t bufsize = PATH_MAX;
                if (_NSGetExecutablePath(szPath, &bufsize))
                {
                    throw Exception::FileSystemException::
                        ExecutableDirectoryUnavailableException(
                            "_NSGetExecutablePath returned error",
                            Logger::Severity::warning);
                }
#else
                char szPath[PATH_MAX];
                ssize_t count = readlink("/proc/self/exe", szPath, PATH_MAX);
                if (count < 0 || count >= PATH_MAX)
                {
                    throw Exception::FileSystemException::
                        ExecutableDirectoryUnavailableException(
                            "/proc/self/exe link size was incorrect",
                            Logger::Severity::warning);
                }
                szPath[count] = '\0';
#endif
                return std::filesystem::path{szPath}.parent_path() / "";
            }
        } // namespace FileSystem
    } // namespace Helpers
} // namespace Sola

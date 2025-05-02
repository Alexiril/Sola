#ifndef SOLA_HELPERS_FILESYSTEM
#define SOLA_HELPERS_FILESYSTEM

#include "sola_common.hpp"

namespace Sola
{
    namespace Helpers
    {
        namespace FileSystem
        {
            EXPORTED std::filesystem::path get_executable_directory(void);
        } // namespace FileSystem
    } // namespace Helpers
} // namespace Sola

#endif

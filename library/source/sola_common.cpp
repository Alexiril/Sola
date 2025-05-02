#include "sola_common.hpp"

namespace Sola
{
    static std::string engine_version_readable = SOLA_VERSION_STRING;

    u64 get_engine_version()
    {
        return (static_cast<u64>(SOLA_VERSION_MAJOR) << 32) + (static_cast<u64>(SOLA_VERSION_MINOR) << 16) +
               static_cast<u64>(SOLA_VERSION_PATCH);
    }

    const std::string &get_engine_version_readable() { return engine_version_readable; }
} // namespace Sola

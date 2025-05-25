#include "SolaCommon.hpp"

namespace Sola {
    static std::string engine_version_readable = SOLA_VERSION_STRING;

    auto getEngineVersion() -> u64 {
        return (static_cast<u64>(SOLA_VERSION_MAJOR) << sizeof(u32)) + (static_cast<u64>(SOLA_VERSION_MINOR) << sizeof(u16)) +
               static_cast<u64>(SOLA_VERSION_PATCH);
    }

    auto getEngineVersionReadable() -> const std::string & { return engine_version_readable; }
} // namespace Sola

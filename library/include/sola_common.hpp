#ifndef SOLA_COMMON
#define SOLA_COMMON

// Python headers inclusion must be highest
#include <Python.h>

#include <SDL3/SDL.h>

#include <array>
#include <cstdint>
#include <expected>
#include <filesystem>
#include <format>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <numeric>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace Sola
{
    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    /// @brief Returns the current engine version in number format. Calculated at
    /// compile time.
    /// @return unsigned 64-bit wide number with major part as highest two bytes, minor
    /// as middle two bytes, patch as smallest two bytes (like \x00\x01 \x00\xF0
    /// \x00\x02 = 4_310_695_938).
    u64 get_engine_version(void);

    const std::string &get_engine_version_readable(void);
} // namespace Sola

// For shared library (windows mostly)

#if defined _WIN32 || defined __CYGWIN__
#    ifdef EXPORT
#        ifdef __GNUC__
#            define EXPORTED __attribute__((dllexport))
#        else
#            define EXPORTED __declspec(dllexport)
#        endif
#    else
#        ifdef __GNUC__
#            define EXPORTED __attribute__((dllimport))
#        else
#            define EXPORTED __declspec(dllimport)
#        endif
#    endif
#else
#    if defined(EXPORT) && __GNUC__ >= 4
#        define EXPORTED __attribute__((visibility("default")))
#        define HIDDEN   __attribute__((visibility("hidden")))
#    endif
#endif

#ifndef EXPORTED
#    define EXPORTED
#endif

#ifndef HIDDEN
#    define HIDDEN
#endif

#endif

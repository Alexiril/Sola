#ifndef SOLACOMMON_HPP
#define SOLACOMMON_HPP

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

/// @brief Sola is the main namespace inside the whole Sola library and most of support tools (like editor). It contains
/// all other objects and namespaces required for Sola to run properly.
namespace Sola {
    /// @brief Smaller alias for a signed fixed-width 8-bit (1 byte) integer type.
    /// @details The range is -128 to 127. On most architectures is the same as signed char.
    using i8 = int8_t;
    /// @brief Smaller alias for a signed fixed-width 16-bit (2 bytes) integer type.
    /// @details The range is -32768 to 32767. On most architectures is the same as signed short.
    using i16 = int16_t;
    /// @brief Smaller alias for a signed fixed-width 32-bit (4 bytes) integer type.
    /// @details The range is -2147483648 to 2147483647. On most architectures is the same as signed int (or signed long
    /// on Windows).
    using i32 = int32_t;
    /// @brief Smaller alias for a signed fixed-width 64-bit (8 bytes) integer type.
    /// @details The range is -9223372036854775808 to 9223372036854775807. On most architectures is the same as signed
    /// long long.
    using i64 = int64_t;

    /// @brief Smaller alias for an unsigned fixed-width 8-bit (1 byte) integer type.
    /// @details The range is 0 to 255. On most architectures is the same as unsigned char.
    using u8 = uint8_t;
    /// @brief Smaller alias for an unsigned fixed-width 16-bit (2 bytes) integer type.
    /// @details The range is 0 to 65535. On most architectures is the same as unsigned short.
    using u16 = uint16_t;
    /// @brief Smaller alias for an unsigned fixed-width 32-bit (4 bytes) integer type.
    /// @details The range is 0 to 4294967295. On most architectures is the same as unsigned int (or unsigned long on
    /// Windows).
    using u32 = uint32_t;
    /// @brief Smaller alias for an unsigned fixed-width 64-bit (8 bytes) integer type.
    /// @details The range is 0 to 65535. On most architectures is the same as unsigned long long (and sometimes it is
    /// the same size as size_t, uintptr_t, or void pointer).
    using u64 = uint64_t;

    /// @brief Smaller alias for a floating point number type.
    using f32 = float; // No support for std::float32_t (stdfloat) in msvc :(
    /// @brief Smaller alias for a double precision floating point number type.
    using f64 = double; // Same with std::float64_t (stdfloat) - no support in msvc :(

    /// @brief Returns the current engine version in number format.
    /// @return unsigned 64-bit wide number with major part as highest two bytes, minor
    /// as middle two bytes, patch as smallest two bytes (like \\x00\\x01 \\x00\\xF0
    /// \\x00\\x02 = 4_310_695_938).
    auto getEngineVersion() -> u64;

    /// @brief Returns the current engine version in human readable format.
    /// @return string with major, minor and patch version numbers (like "0.1.2").
    auto getEngineVersionReadable() -> const std::string &;
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

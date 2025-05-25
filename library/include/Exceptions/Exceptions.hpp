#ifndef EXCEPTIONS_EXCEPTIONS_HPP
#define EXCEPTIONS_EXCEPTIONS_HPP

/// @brief This namespace contains Sola exceptions
/// @attention Sola **does not** use any exceptions in a normal case. Catching those exceptions is considered to be
/// **very slow** comparing to no-exception case. We do not prohibit C++ standard exceptions explicitly (like with
/// the compiler flags), but you should always consider using a different, faster approach (like std::expected or
/// std::optional) if possible. In general, Sola uses exceptions **only** if something outstanding, really severe
/// happened, if the time that it takes to handle this exception is not relevant anymore, like serious crash, like
/// not enough memory error, etc. When the application needs to stop anyway to handle this.
namespace Sola::Exceptions {} // namespace Sola::Exceptions

#endif // EXCEPTIONS_EXCEPTIONS_HPP

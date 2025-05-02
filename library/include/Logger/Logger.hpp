#ifndef SOLA_LOGGER_LOGGER
#define SOLA_LOGGER_LOGGER

#include "Logger/Severity.hpp"
#include "sola_common.hpp"

namespace Sola
{

    namespace Logger
    {
        EXPORTED void print_log(const std::string &file, u64 line, const std::string &what, Severity severity);
    } // namespace Logger
} // namespace Sola

#define print(what, severity) Sola::Logger::print_log(__FILE__, __LINE__, what, severity)
#define print_debug(what)     print(what, Sola::Logger::Severity::debug)
#define print_info(what)      print(what, Sola::Logger::Severity::info)
#define print_warning(what)   print(what, Sola::Logger::Severity::warning)
#define print_error(what)     print(what, Sola::Logger::Severity::error)
#define print_fatal(what)     print(what, Sola::Logger::Severity::fatal)

#endif

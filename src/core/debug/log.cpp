
#include "log.hpp"
#include "fmt/base.h"

void Debug::m_Log(fmt::string_view fmt, fmt::format_args args)
{
    fmt::vprint(fmt, args);
}

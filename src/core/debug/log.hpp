#pragma once

#include <fmt/base.h>

class Debug {
public:
    //wrapper for fmt::print
    template<typename... T>
    static void log(fmt::format_string<T...> fmt, T&&... args)
    {
        fmt::vargs<T...> va = {{args...}};
        Debug::m_Log(fmt.str, va);
    }

private:
    static void m_Log(fmt::string_view fmt, fmt::format_args args);   
};

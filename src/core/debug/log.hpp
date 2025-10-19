#pragma once

#include <fmt/base.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>

class Debug {
public:
    //wrapper for fmt::print
    template<typename... T>
    static void log(fmt::format_string<T...> fmt, T&&... args)
    {
        fmt::vargs<T...> va = {{args...}};
        Debug::m_Log(fmt.str, va);
    }
    template<typename... T>
    static void error(fmt::format_string<T...> fmt, T&&... args)
    {
        fmt::vargs<T...> va = {{args...}};
        Debug::m_Error(fmt, va);
    }


    static void glfwErrorCallback(int error, const char* message);
    static void GLErrorCallback(
                GLenum source,
                GLenum type,
                GLuint id,
                GLenum severity,
                GLsizei length,
                const GLchar* message,
                const void* userParam
            );
private:
    static void m_Log(fmt::string_view fmt, fmt::format_args args);   
    static void m_Error(fmt::string_view fmt, fmt::format_args args);
};

//formats for fmt

template <> struct fmt::formatter<glm::mat4>: formatter<string_view> {
    auto format(glm::mat4 mat, fmt::format_context& ctx) const 
        -> fmt::format_context::iterator;
};



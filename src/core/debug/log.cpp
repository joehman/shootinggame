
#include "log.hpp"
#include "fmt/base.h"
#include "fmt/format.h"

void Debug::m_Log(fmt::string_view fmt, fmt::format_args args)
{
    fmt::vprint(fmt, args);
    fmt::print("\n");
}

void Debug::m_Error(fmt::string_view fmt, fmt::format_args args)
{
    fmt::print("[ERROR]: ");
    fmt::vprint(fmt, args);
}

void Debug::GLErrorCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{

    const char* severitystr;
    switch(severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            severitystr = "SEVERITY_HIGH";
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            severitystr = "SEVERITY_MEDIUM";
            break;
        case GL_DEBUG_SEVERITY_LOW:
            severitystr = "SEVERITY_LOW";
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            severitystr = "SEVERITY_NOTIFICATION";
            break;
    }
    Debug::log("[OpenGL][{}]: {}", severitystr, message);
}

void Debug::glfwErrorCallback(int error, const char* message)
{
    Debug::log("[GLFW ERROR][CODE {}]: {}", error, message);    
}

auto fmt::formatter<glm::mat4>::format(glm::mat4 mat, fmt::format_context& ctx) const 
    -> fmt::format_context::iterator
{
    std::string out = "";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            out += fmt::to_string(mat[i][j]);
            out += "\t";
        }
        out += "\n";
    }

    return formatter<string_view>::format(out, ctx); 
}


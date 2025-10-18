#pragma once

#include <core/window/window.hpp>
#include <glad/glad.h>



#ifndef GL_VERSION_MAJOR
    #define GL_VERSION_MAJOR 3
#endif

#ifndef GL_VERSION_MINOR
    #define GL_VERSION_MINOR 3
#endif

class Game {
public:

    Game(const int GLVersionMajor, const int GLVersionMinor);
    ~Game();

    void init(int width, int height, const char* title, bool fullscreen);
    void start();

private:
    void frame();

private:
    Window m_Window;

};

void debugCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
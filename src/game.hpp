#pragma once

#include <core/window/window.hpp>
#include <glad/glad.h>

struct GameSettings {
    WindowSettings windowSettings;
};

class Game {
public:
    void init(GameSettings settings);
    void start();


private:
    void frame();
    void setActualGLVersion(); // Polls OpenGL to get the actual current opengl version.
    bool minGLVersion(int GLVersionMajor, int GLVersionMinor);


private:
    Window m_Window;

    int m_GLVersionMajor = -1;
    int m_GLVersionMinor = -1;
};

void debugCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

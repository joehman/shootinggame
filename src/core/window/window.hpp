#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct WindowSettings {
    const int width;
    const int height;
    const char* name;

    const bool fullscreen;
};

class Window 
{
public:
    void create(WindowSettings setttings);
    Window(WindowSettings settings);
    Window() {}
    ~Window();    

    void updateWindow();
    void close();
    void makeContextCurrent();

    int getWidth();
    int getHeight();
    bool shouldClose();
    GLFWwindow* getWindow();

    static void init(int desiredGLVersionMajor, int desiredGLVersionMinor, GLFWerrorfun glfwErrorCallback);
    static void loadGL();
private:
    GLFWwindow* m_Window;

};

#endif


#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
class Window 
{
public:

    Window(int width, int height, const char* name, bool fullscreen);
    Window() {}
    ~Window();    

    void create(int width, int height, const char* name, bool fullscreen);

    void updateWindow();
    int getWidth();
    int getHeight();

    bool shouldClose();

    GLFWwindow* getWindow();
private:
    GLFWwindow* m_Window;

};

#endif


#include <iostream>

#include "window.hpp"

Window::~Window()
{
    glfwDestroyWindow(m_Window);
}
void Window::create(int width, int height, const char* name, bool fullscreen)
{
    if (!fullscreen)
    {
        m_Window = glfwCreateWindow(width, height, name, NULL, NULL);
    } else
    {
        m_Window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);    
    }
    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        throw std::runtime_error("Failed to initialize GLFWwindow! ");
    }

    glfwMakeContextCurrent(this->m_Window);
}

Window::Window(int width, int height, const char* name, bool fullscreen)
{
    this->create(width, height, name, fullscreen);
}

GLFWwindow* Window::getWindow()
{
    return m_Window; 
}

int Window::getHeight()
{
    int height = 0;
    glfwGetWindowSize(m_Window, nullptr, &height); 
    
    return height;
}

int Window::getWidth()
{
    int width = 0;
    glfwGetWindowSize(m_Window, &width, nullptr);

    return width;
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

void Window::updateWindow()
{
    glfwSwapBuffers(this->m_Window);
    glfwPollEvents();
}

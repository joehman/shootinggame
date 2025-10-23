#include <glad/glad.h>
#include <core/debug/log.hpp>

#include "window.hpp"
#include "GLFW/glfw3.h"

void Window::init(int desiredGLVersionMajor, int desiredGLVersionMinor, GLFWerrorfun glfwErrorCallback)
{
    if (!glfwInit())
    {
        Debug::error("Failed to initialize GLFW!");
        return;
    }
    glfwSetErrorCallback(glfwErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, desiredGLVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, desiredGLVersionMinor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}
void Window::loadGL()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Debug::error("Failed to load OpenGL!");
    } 
}

void Window::create(WindowSettings settings)
{
    if (!settings.fullscreen)
    {
        m_Window = glfwCreateWindow(settings.width, settings.height, settings.name, NULL, NULL);
    } else
    {
        m_Window = glfwCreateWindow(settings.width, settings.height, settings.name, glfwGetPrimaryMonitor(), NULL);    
    }
    if (m_Window == NULL)
    {
        Debug::error("Failed to create glfwWindow!");
    }
}

void Window::makeContextCurrent()
{
    glfwMakeContextCurrent(this->m_Window);
}

Window::Window(WindowSettings settings)
{
    this->create(settings);
}

Window::~Window()
{
    glfwDestroyWindow(m_Window);
}

void Window::close()
{
    glfwSetWindowShouldClose(this->m_Window, GLFW_TRUE);
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


bool Window::getKey(int key)
{
    if (glfwGetKey(this->m_Window, key) == GLFW_PRESS)
    {
        return true;
    }
    return false;
}

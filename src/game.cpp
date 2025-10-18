
#include <game.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <ecs/scene.hpp>
#include <ecs/entity.hpp>

#include <components/rendercomp.hpp>
#include <systems/rendersystem.hpp>

#include <core/debug/log.hpp>

Scene mainScene;

//for testing
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f
};

void Game::start()
{

    Entity testobj(mainScene);

    Shader shader("shaders/vshader.vert", "shaders/fshader.frag");
    std::vector<float> vec(sizeof(vertices));

    vec.assign(&vertices[0], &vertices[9]);

    testobj.AddComponent<MeshRender>(Mesh(vec, shader));

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    frame();
}

void Game::frame()
{
    
    RenderSystem_init(mainScene);

    std::cout << "hello, wordL!";

    bool once = false;
    //while (!m_Window.shouldClose())
    while (!once)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        RenderSystem_update(mainScene);

        m_Window.updateWindow();
        
        once = true;
    }
}

Game::~Game()
{
    //glfwTerminate();
}

void glfwErrorCallback(int error, const char* description) {
    std::cerr << "GLFW Error [" << error << "]: " << description << std::endl;
}

Game::Game(const int GLVersionMajor, const int GLVersionMinor)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        throw std::runtime_error("Failed to initialize GLFW!");
    }
    glfwSetErrorCallback(glfwErrorCallback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLVersionMinor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Game::init(int width, int height, const char* title, bool fullscreen)
{
    m_Window.create(800, 600, "game", false);

    glfwMakeContextCurrent(m_Window.getWindow());

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load OpenGL!" << std::endl;
        throw std::runtime_error("Failed to load OpenGL! Program::Program()!");
    } 

    glEnable(GL_DEPTH_TEST);
    glViewport(0,0, m_Window.getWidth(), m_Window.getHeight());

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(&debugCallback, nullptr);
}
void debugCallback(
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

    std::println("[OpenGL {}]: {}", severitystr, message);
}
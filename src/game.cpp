#include <game.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ecs/scene.hpp>
#include <ecs/entity.hpp>

#include <components/meshfilter.hpp>
#include <components/transform.hpp>
#include <components/camera.hpp>

#include <systems/rendersystem.hpp>

#include <core/debug/log.hpp>

Scene mainScene;

//for testing
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f
};

void Game::init(GameSettings settings)
{
    Window::init(3, 3, Debug::glfwErrorCallback);

    m_Window.create(settings.windowSettings);
    m_Window.makeContextCurrent();

    Window::loadGL();
    
    this->setActualGLVersion();
    
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0, m_Window.getWidth(), m_Window.getHeight());

    if (this->minGLVersion(4,3))
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(&Debug::GLErrorCallback, nullptr);
    }
}

void Game::start()
{
    Entity camera(mainScene);
    Entity testobj(mainScene);

    std::vector<float> vec(sizeof(vertices));
    vec.assign(&vertices[0], &vertices[9]);

    testobj.AddComponent<Transform>(glm::vec3(0,0,0), glm::vec3(1,1,1), glm::vec3(0,0,0));
    testobj.AddComponent<MeshFilter>(Mesh(vec));

    camera.AddComponent<Transform>(glm::vec3(0,0, -3.0f), glm::vec3(1,1,1), glm::vec3(0,0,0));
    camera.AddComponent<Camera>((float)m_Window.getWidth()/(float)m_Window.getHeight());

    RenderSystem::setMainCamera(&camera);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    frame();
}

void Game::frame()
{ 
    RenderSystem::init(mainScene);

    while (!m_Window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        RenderSystem::update(mainScene);

        m_Window.updateWindow();
    
        if (glfwGetKey(m_Window.getWindow(), GLFW_KEY_ESCAPE))
        {
            m_Window.close();
        }
    }
}

void Game::setActualGLVersion()
{
    glGetIntegerv(GL_MAJOR_VERSION, &this->m_GLVersionMajor);
    glGetIntegerv(GL_MINOR_VERSION, &this->m_GLVersionMinor);
}

bool Game::minGLVersion(int GLVersionMajor, int GLVersionMinor)
{
    // m_GLVersionMajor and Minor are both -1 by default
    if (this->m_GLVersionMajor <= 0 || this->m_GLVersionMinor < 0 )
    {
        Debug::log("Can't check GLversion: Current GLVersion not set!");
        return false; // will always return false, -1 is not a valid version
    }

    if (this->m_GLVersionMinor >= GLVersionMinor && this->m_GLVersionMajor >= GLVersionMajor)
    {
        return true;
    }
    return false;
}


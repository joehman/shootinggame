#include "playersystem.hpp"
#include "core/window/window.hpp"
#include <components/player.hpp>
#include <components/transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include <core/time.hpp>

Entity* PlayerSystem::player = NULL;

void PlayerSystem::start(Entity* player)
{
    PlayerSystem::player = player;
}

glm::vec3 getDesiredDir()
{
    Entity* player = PlayerSystem::getPlayer();
    auto comp = player->GetComponent<Player>();

    glm::vec3 dir = glm::vec3(0,0,0);
    
    if (comp.window->getKey(GLFW_KEY_W))
    {
        dir += glm::vec3(0, 0, 1); 
    }
    if (comp.window->getKey(GLFW_KEY_A))
    {
        dir += glm::vec3(-1, 0, 0);
    }
    if (comp.window->getKey(GLFW_KEY_S))
    {
        dir += glm::vec3(0, 0, -1);
    }
    if (comp.window->getKey(GLFW_KEY_D))
    {
        dir += glm::vec3(1, 0, 0);
    }
    if (glm::length(dir) > 0)
    {
        dir = glm::normalize(dir);
    }

    return dir;
}

glm::vec3 getDesiredRotation()
{
    auto& window = PlayerSystem::getPlayer()->GetComponent<Player>().window;

    glm::vec3 dir = glm::vec3(0,0,0);

    if (window->getKey(GLFW_KEY_LEFT))
    {
        dir += glm::vec3(0,1,0);
    }
    if (window->getKey(GLFW_KEY_RIGHT))
    {
        dir += glm::vec3(0,-1,0);
    }
    if (window->getKey(GLFW_KEY_UP))
    {
        dir += glm::vec3(1,0,0);
    }
    if (window->getKey(GLFW_KEY_DOWN))
    {
        dir += glm::vec3(-1,0,0);
    }
    return dir;
}

void PlayerSystem::update()
{
    auto& transform = player->GetComponent<Transform>();

    glm::vec3 desiredDir = getDesiredDir();
    glm::vec3 dir = desiredDir.x*transform.right() + desiredDir.z*transform.forwards();

    transform.setPosition(transform.getPosition() + dir * Time::deltaTime());
    transform.setRotation(transform.getRotation() + getDesiredRotation() * Time::deltaTime());

    Debug::log("");
    Debug::log("Left:\t\t{}", glm::to_string(transform.left()));
    Debug::log("Right:\t\t{}", glm::to_string(transform.right()));
    Debug::log("Forwards:\t{}", glm::to_string(transform.forwards()));
    Debug::log("Backwards:\t{}", glm::to_string(transform.backwards()));
}

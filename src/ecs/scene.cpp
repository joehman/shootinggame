#include "scene.hpp"
#include "entity.hpp"
#include <iostream>


entt::entity Scene::createEntity()
{
    return m_Registry.create();
}
bool Scene::entityExists(Entity ent)
{
    if (m_Registry.valid(ent.getEntityID()))
    {
        return true;
    }
    return false;
}
void Scene::destroyEntity(Entity ent)
{
    if (entityExists(ent))
    {
        m_Registry.destroy(ent.getEntityID());
        return;
    }
    std::cout << "Cannot destroy Entity which does not exist! " << std::endl;
}
auto Scene::getAllEntities()
{
    return m_Registry.view<entt::entity>();
}
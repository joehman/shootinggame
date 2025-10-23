//The scene stores, creates and keeps track of all Entities.

#pragma once

#include <entt/entt.hpp>

class Entity;

class Scene {
public:
    Scene() {}

    entt::entity createEntity();
    void destroyEntity();

    template<typename Type>
    auto getEntitiesWithComponent()
    {
        return m_Registry.view<Type>();
    }

    //don't really know if this function works, returns a view.
    auto getAllEntities();

    bool entityExists(Entity ent);
    void destroyEntity(Entity ent);

    entt::registry& getRegistry() { return m_Registry; }

private:
    entt::registry m_Registry;


};

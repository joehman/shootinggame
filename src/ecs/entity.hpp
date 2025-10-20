#pragma once

#include <entt/entt.hpp>
#include "scene.hpp"

#include <core/debug/log.hpp>

class Entity {
public:
    Entity(Scene& scene);
    
    bool exists();

    template<typename Type>
    inline bool HasComponent()
    {
        return m_Scene.getRegistry().all_of<Type>(m_Entity);
    }
    template<typename Type, typename ...Args>
    inline void AddComponent(Args ...args)
    {
        if (HasComponent<Type>())
        {
            Debug::log("Cannot add a Component which an Entity already has!");
            return;
        }
        m_Scene.getRegistry().emplace<Type>(m_Entity, args...);
    }

    template<typename Type>
    inline void RemoveComponent()
    {
        if (!HasComponent<Type>())
        {
            Debug::log("Cannot remove a Component which an Entity does not have!");
        }
        m_Scene.getRegistry().erase<Type>(m_Entity);
    }
    template<typename Type>
    inline auto& GetComponent()
    {
        if (!HasComponent<Type>())
        {
            throw std::runtime_error("Cannot get a Component which an Entity does not have!");
        }
        return m_Scene.getRegistry().get<Type>(m_Entity);
    }

    entt::entity getEntityID() { return m_Entity; }
private:
    entt::entity m_Entity;
    Scene& m_Scene;
};

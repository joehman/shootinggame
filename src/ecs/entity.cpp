#include "entity.hpp"

Entity::Entity(Scene& scene) : m_Scene(scene) 
{
    this->m_Entity = m_Scene.createEntity();
}

bool Entity::exists()
{
    return m_Scene.entityExists(*this);
}

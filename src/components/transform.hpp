#pragma once

#include <glm/glm.hpp>

struct Transform {
public:
    Transform(glm::vec3 position = {0,0,0}, glm::vec3 scale = {1,1,1}, glm::vec3 rotation = {0,0,0})
        : m_Position(position),
          m_Scale(scale),
          m_Rotation(rotation),
          m_HasChanged(true)
    {};

    void setPosition(glm::vec3 position);
    void setScale(glm::vec3 scale);
    void setRotation(glm::vec3 rotation);

    bool hasChanged() const { return m_HasChanged; }

    glm::vec3 getPosition() const { return m_Position; };
    glm::vec3 getScale() const { return m_Scale; };
    glm::vec3 getRotation() const { return m_Rotation; };


    glm::vec3 right();
    glm::vec3 left();
    glm::vec3 up();
    glm::vec3 down();
    glm::vec3 forwards();
    glm::vec3 backwards();

    glm::mat4 getModel();
    glm::mat4 getViewModel();
private:
    glm::vec3 m_Position;
    glm::vec3 m_Scale;
    glm::vec3 m_Rotation;

    glm::mat4 m_Model;
    bool m_HasChanged;
};

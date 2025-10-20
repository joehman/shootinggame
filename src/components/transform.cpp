
#include "transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Transform::setPosition(glm::vec3 position)
{
    this->m_Position = position;
    if (position != this->m_Position)
    {
        this->m_HasChanged = true;
    }
}

void Transform::setScale(glm::vec3 scale)
{
    this->m_Scale = scale;
    if (this->m_Scale != scale)
    {
        this->m_HasChanged = true;
    }
}

void Transform::setRotation(glm::vec3 rotation)
{
    this->m_Rotation = rotation;

    if (this->m_Rotation != rotation)
    {
        this->m_HasChanged = true;
    }
}

glm::mat4 Transform::getModel()
{
    if (!this->m_HasChanged)
    {
        return this->m_Model;
    }

    this->m_Model = glm::mat4(1.0f);
    this->m_Model = glm::translate(this->m_Model, this->m_Position);
    //ADD ROTATION HERE
    this->m_Model = glm::scale(this->m_Model, this->m_Scale);

    return m_Model; 
}

/*
glm::vec3 Transform::right() 
{
    // in world-space
    glm::vec3 up(0, 1, 0); 

    return glm::normalize(glm::cross(up, this->backwards() ));
}
glm::vec3 Transform::left()
{
    return glm::vec3(0,0,0);
}
glm::vec3 Transform::up()
{
    return glm::vec3(0,0,0);
}
glm::vec3 Transform::down()
{
    return glm::vec3(0,0,0);
}
glm::vec3 forwards()
{
    return glm::vec3(0,0,0);
}
glm::vec3 backwards()
{
    return glm::vec3(0,0,0);
}
*/

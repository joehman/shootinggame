
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
    
    this->m_Model = glm::scale(this->m_Model, this->m_Scale);

    this->m_Model = glm::rotate(this->m_Model, glm::radians(this->m_Rotation.x), {1,0,0});
    this->m_Model = glm::rotate(this->m_Model, glm::radians(this->m_Rotation.y), {0,1,0});
    this->m_Model = glm::rotate(this->m_Model, glm::radians(this->m_Rotation.z), {0,0,1});

    this->m_Model = glm::translate(this->m_Model, this->m_Position);

    this->m_HasChanged = false;

    return m_Model; 
}
glm::mat4 Transform::getViewModel()
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::rotate(model, -m_Rotation.z, glm::vec3(0,0,1));
    model = glm::rotate(model, -m_Rotation.x, glm::vec3(1,0,0));
    model = glm::rotate(model, -m_Rotation.y, glm::vec3(0,1,0));

    model = glm::translate(model, -m_Position);

    return model;
}

glm::vec3 Transform::right() 
{
    return getModel()[0];
}
glm::vec3 Transform::left()
{
    return -right();
}
glm::vec3 Transform::up()
{
    return getModel()[1];
}
glm::vec3 Transform::down()
{
    return -up();
}
glm::vec3 Transform::backwards()
{
    return getModel()[2];
}
glm::vec3 Transform::forwards()
{
    return -backwards();
}

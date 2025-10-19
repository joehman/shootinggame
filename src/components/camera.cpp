#include "camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float ratio, float fov, float near, float far)
    : m_Projection(1.0f) 
{
    set(ratio, fov, far, near);
}
        
void Camera::set(float aspectratio, float fov, float near, float far)
{
    this->m_Projection = glm::perspective(glm::radians(fov), aspectratio, near, far);
}

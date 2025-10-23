
#include <glm/glm.hpp>
#include <components/transform.hpp>

struct Camera {
public:
    // aspectratio is usually screenWidth / screenHeight
    Camera(float aspectratio, float fov = 45.0f, float near = 1000.0f, float far = 0.1f);
    
    void set(float aspectratio, float fov, float far, float near);

    glm::mat4 getProjection() const { return m_Projection; } 
private:
    glm::mat4 m_Projection; 
};

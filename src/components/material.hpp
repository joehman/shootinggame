
#include <glad/glad.h>
#include <core/gfx/shader.hpp>

struct Material {
    Material (Shader shader) :
        shader(shader)
    {}


    Shader shader;
};

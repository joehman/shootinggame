#include "mesh.hpp"

#include <core/gfx/shader.hpp>

Mesh::Mesh(std::vector<float> vertices, Shader shader) : shader(shader) 
{
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    this->vertices = vertices;
}
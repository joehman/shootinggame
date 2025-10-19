#pragma once

#include "shader.hpp"
#include <vector>
#include <glm/glm.hpp>

struct Vertex {
    Vertex () {}
    Vertex(glm::vec3 position) : position(position)
    { }
    glm::vec3 position;
};

class Mesh {
public:
    Mesh() { glGenBuffers(1, &VBO); glGenVertexArrays(1, &VAO); vertices = {}; }
    Mesh(std::vector<float> vertices);

public:
    std::vector<float> vertices;
    
    unsigned int VAO, VBO;
};

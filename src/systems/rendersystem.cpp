#include "rendersystem.hpp"

#include <glad/glad.h>
#include <ecs/scene.hpp>
#include <components/rendercomp.hpp>


void RenderSystem_update(Scene& scene)
{
    auto renderEntities = scene.getEntitiesWithComponent<MeshRender>();

    for (auto entity : renderEntities)
    {

        auto comp = scene.getRegistry().get<MeshRender>(entity);
        
        comp.mesh.shader.use();

        glBindVertexArray(comp.mesh.VAO);
        glDrawArrays(GL_TRIANGLES, 0, 9);
    }

}
void RenderSystem_init(Scene& scene)
{
    auto renderEntities = scene.getEntitiesWithComponent<MeshRender>();

    for (auto entity : renderEntities)
    {
        auto comp = scene.getRegistry().get<MeshRender>(entity);

        glBindVertexArray(comp.mesh.VAO);

        glBindBuffer(GL_ARRAY_BUFFER, comp.mesh.VBO);
        glBufferData(GL_ARRAY_BUFFER, comp.mesh.vertices.size() * sizeof(float), &comp.mesh.vertices[0], GL_STATIC_DRAW);
        
        // for the vertices, eg. Vertex.position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

}
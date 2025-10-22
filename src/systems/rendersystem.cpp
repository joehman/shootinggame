#include "rendersystem.hpp"

#include <glad/glad.h>
#include <ecs/scene.hpp>

#include <core/debug/log.hpp>

#include <components/meshfilter.hpp>
#include <components/transform.hpp>
#include <components/camera.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <ecs/entity.hpp>

Entity* RenderSystem::mainCamera = NULL;
Shader defaultShader;

void RenderSystem::update(Scene& scene)
{
    if (mainCamera == NULL)
    {
        Debug::log("No Camera in Scene! Set Main Camera with RenderSystem::setMainCamera!");
        return;
    }

    auto renderEntities = scene.getEntitiesWithComponent<MeshFilter>();

    for (auto entity : renderEntities)
    {
        auto meshfilter = scene.getRegistry().try_get<MeshFilter>(entity);
        auto transform = scene.getRegistry().try_get<Transform>(entity);
        
        auto camera = mainCamera->GetComponent<Camera>();
        auto view = mainCamera->GetComponent<Transform>();

        if (transform == NULL)
        {
            Debug::log("Entity {} has MeshFilter but no Transform!", (int)entity);
            continue; // skip
        }

        //auto shader = scene.getRegistry().get<Material>(entity); 

        defaultShader.use();
        
        defaultShader.setMat4("perspective", camera.getProjection());
        defaultShader.setMat4("model", transform->getModel());
        defaultShader.setMat4("view", glm::inverse(view.getModel()));
            
        glBindVertexArray(meshfilter->mesh.VAO);
        glDrawArrays(GL_TRIANGLES, 0, meshfilter->mesh.vertices.size());
    }

}
void RenderSystem::init(Scene& scene)
{
    defaultShader = Shader("shaders/vshader.vert", "shaders/fshader.frag");
    auto renderEntities = scene.getEntitiesWithComponent<MeshFilter>();

    for (auto entity : renderEntities)
    {
        auto meshfilter = scene.getRegistry().get<MeshFilter>(entity);

        glBindVertexArray(meshfilter.mesh.VAO);

        glBindBuffer(GL_ARRAY_BUFFER, meshfilter.mesh.VBO);
        glBufferData(GL_ARRAY_BUFFER, meshfilter.mesh.vertices.size() * sizeof(float), &meshfilter.mesh.vertices[0], GL_STATIC_DRAW);
        
        // for the vertices, eg. Vertex.position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        meshfilter.buffered = true;
    }
}

void RenderSystem::setMainCamera(Entity* camera)
{
    RenderSystem::mainCamera = camera;
}

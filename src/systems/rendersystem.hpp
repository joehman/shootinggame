#include <ecs/scene.hpp>
#include <core/gfx/shader.hpp>

class RenderSystem 
{
public:
    static void setMainCamera(Entity* camera);

    static void update(Scene& scene);
    static void init(Scene& scene);

    static Entity* mainCamera;
};


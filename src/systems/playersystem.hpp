#include <ecs/entity.hpp>

class PlayerSystem 
{
public:
    static void start(Entity* player);
    static void update();

    static Entity* getPlayer() { return PlayerSystem::player; }

private:
    static Entity* player; 
};

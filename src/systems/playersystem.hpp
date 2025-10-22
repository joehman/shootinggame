#include <ecs/entity.hpp>

class PlayerSystem 
{
public:
    static void start(const Scene& mainScene);
    static void update(const Scene& mainScene);

private:
    static Entity* player; 
};

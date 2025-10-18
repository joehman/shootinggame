#define GLFW_INCLUDE_NONE

#include <game.hpp>
#include <core/debug/log.hpp>

int main()
{
    Game game = Game(4,3);

    game.init(800,600, "game", false);

    game.start();
}

#define GLFW_INCLUDE_NONE
#include <game.hpp>

int main()
{
    Game game;

    game.init((GameSettings){
        .windowSettings = (WindowSettings){
            .width = 800,
            .height = 600,

            .name = "Game",
            .fullscreen = false,
        }
    });

    game.start();
}

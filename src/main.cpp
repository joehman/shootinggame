#define GLFW_INCLUDE_NONE
#include <game.hpp>

int main()
{
    Game game;

    game.init((GameSettings){
        .windowSettings = (WindowSettings){
            .width = 1920,
            .height = 1080,

            .name = "Game",
            .fullscreen = false,
        }
    });

    game.start();
}

#include <core/window/window.hpp>

struct Player 
{
    Player(Window* window, float sensitivity = 1.0f) :
        sensitivity(sensitivity),
        window(window)
    {}

    float sensitivity;
    Window* window;
};

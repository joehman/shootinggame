#include <chrono>

class Time 
{
public:
    static void gameStart();

private:
    static std::chrono::steady_clock::time_point m_ApplicationStart;
    static std::chrono::steady_clock::time_point m_GameStart;
};

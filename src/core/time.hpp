#include <chrono>

class Time 
{
public:
    static std::chrono::steady_clock::time_point now(); 
    
    static void frameStart(); 

    static float deltaTime() { return m_DeltaTime; }
private:
    
    static std::chrono::steady_clock::time_point m_LastFrame;
    static float m_DeltaTime;
};

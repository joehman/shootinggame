#include "time.hpp"
#include <chrono>

using _clock = std::chrono::steady_clock;

_clock::time_point Time::m_LastFrame;
float Time::m_DeltaTime = 0;

_clock::time_point Time::now()
{
    return _clock::now();
}
    
void Time::frameStart()
{ 
    auto now = Time::now();
    
    Time::m_DeltaTime = std::chrono::duration<float>(now - m_LastFrame).count();

    Time::m_LastFrame = now; 
}


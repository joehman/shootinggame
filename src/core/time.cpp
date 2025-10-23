#include "time.hpp"
#include <chrono>

using _clock = std::chrono::steady_clock;

_clock::time_point Time::m_PreviousFrame = Time::now();

float Time::m_DeltaTime = 0;
float Time::m_Time = 0;

_clock::time_point Time::now()
{
    return _clock::now();
}
    
void Time::frameStart()
{ 
    auto now = Time::now();
    
    Time::m_DeltaTime = std::chrono::duration<float>(now - m_PreviousFrame).count();
    Time::m_PreviousFrame = now;

    Time::m_Time += m_DeltaTime;
}

void Timer::start()
{
    m_StartTime = _clock::now();
    m_HasStarted = true;
}
void Timer::end()
{
    m_EndTime = _clock::now();
}
float Timer::elapsed()
{
    if (!m_HasStarted)
    {
        return 0;
    }
    return std::chrono::duration<float>(Time::now() - m_StartTime).count(); 
}

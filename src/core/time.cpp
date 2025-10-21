#include "time.hpp"

using _clock = std::chrono::steady_clock;

_clock::time_point Time::m_PreviousFrame = Time::now();
float Time::m_DeltaTime = 0;

_clock::time_point Time::now()
{
    return _clock::now();
}

void Time::frameStart()
{
    m_DeltaTime = std::chrono::duration<float>(Time::now() - m_PreviousFrame).count();

    m_PreviousFrame = Time::now();
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


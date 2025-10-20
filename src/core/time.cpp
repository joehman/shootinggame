#include "time.hpp"

using namespace std::chrono;

steady_clock::time_point Time::m_ApplicationStart = steady_clock::now();
steady_clock::time_point Time::m_GameStart = m_ApplicationStart;

void Time::gameStart()
{
    m_GameStart = steady_clock::now();
}

#include <chrono>

class Time 
{
public:
    static std::chrono::steady_clock::time_point now(); 
    
    static void frameStart(); 

    static float deltaTime() { return m_DeltaTime; }
private:
    static std::chrono::steady_clock::time_point m_PreviousFrame;
    static float m_DeltaTime;
};

class Timer {
public:
    //Start the timer.
    void start();

    //End the timer.
    void end();
    
    // Returns either the amount of time passed since start() was called, 
    // or the amount if time that passed between start() and end() being called, in seconds.
    // If start() has not been called, this returns 0.
    float elapsed();

private:
    std::chrono::steady_clock::time_point m_StartTime;
    std::chrono::steady_clock::time_point m_EndTime;
    
    bool m_HasStarted;
};

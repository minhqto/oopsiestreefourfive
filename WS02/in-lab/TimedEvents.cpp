#include "TimedEvents.h"
namespace sdds
{
    TimedEvents::TimedEvents()
    {
        numRecs = 0;
    }

    std::chrono::steady_clock::time_point TimedEvents::startClock()
    {
        return std::chrono::steady_clock::now();
    }
    
    std::chrono::steady_clock::time_point TimedEvents::stopClock()
    {
        return std::chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const std::string src)
    {
        TimedEvents::Event::eventName = src;
    }
}
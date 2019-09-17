#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

class TimedEvents{

    int numRecs;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    
    struct{
        std::string eventName;
        std::string unitTime;
        std::chrono::steady_clock::duration dur;
    } Event;
    
    Event arr[7];

    public:
    TimedEvents();
    std::chrono::steady_clock::time_point startClock();
    std::chrono::steady_clock::time_point stopClock();
    void recordEvent(const std::string);

};

std::ostream& operator<<(std::ostream&, TimedEvents&);

#endif

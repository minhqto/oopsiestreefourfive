// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds{

const unsigned int maxArrSize = 7;

class TimedEvents{

    unsigned int numRecs = 0;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    struct{
            std::string eventName;
            std::string unitTime;
            std::chrono::steady_clock::duration dur;
    } time[maxArrSize]; 

    public: 
    
        TimedEvents();
        unsigned int getNumRecs() const;
        void startClock();
        void stopClock();
        void recordEvent(const std::string);
        friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
};

}
#endif

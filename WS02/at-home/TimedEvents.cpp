// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "TimedEvents.h"

namespace sdds
{

    TimedEvents::TimedEvents()
    {
        numRecs = 0;
    }

    void TimedEvents::startClock()
    {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock()
    {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const std::string src)
    {
        auto et = endTime;
        auto st = startTime;

        if(numRecs <= maxArrSize){
            time[numRecs].eventName = src;
            time[numRecs].unitTime = "nanoseconds";
            time[numRecs].dur = et-st;
            numRecs++;
        }   
    }

    unsigned int TimedEvents::getNumRecs() const
    {
        return numRecs;
    }

    std::ostream& operator<<(std::ostream& os, const TimedEvents& src)
    {

        unsigned int recs = src.getNumRecs();
        os << "--------------------------\n" << "Execution Times:\n" << "--------------------------" << std::endl;
        for(unsigned int i = 0; i < recs; i++){
            os.width(20);
            os.setf(std::ios::left);
            os << src.time[i].eventName;

            os.unsetf(std::ios::left);
            os.width(12);
            os.setf(std::ios::right);

            os << ' ' << std::chrono::duration_cast<std::chrono::nanoseconds>(src.time[i].dur).count();
            os << ' ' << src.time[i].unitTime;

            os.unsetf(std::ios::right);
            

            os << std::endl;
        }
        os << "--------------------------\n";
        return os;
    }
}
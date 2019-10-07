// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include <iomanip>
#include <array>


namespace sdds
{
    //holds information about a single reservation at a restaurant for a date/time in October.
    class Reservation{
        
        std::string resId;
        std::string name;
        std::string email;
        unsigned int numParty;
        unsigned int day;
        unsigned int hour;
        
        public:

        Reservation();
        Reservation(const std::string& m_res); 
        ~Reservation();
        int getTime() const;
        void display(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, const Reservation&);

    };

     





}




#endif

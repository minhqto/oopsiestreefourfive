// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef RACECAR_H
#define RACECAR_H

#include "Car.h"
#include <fstream>
#include <string>


namespace sdds{

    class Racecar : public Car{

        double m_booster;

        public:
        Racecar();
        Racecar(std::istream&);
        void display(std::ostream&) const;
        double topSpeed() const;

    };
}


#endif

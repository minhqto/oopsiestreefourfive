// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef CAR_H
#define CAR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Vehicle.h"


namespace sdds
{

    class Car : public Vehicle{

        std::string maker;
        std::string carCondition;
        double top_speed;


        public:
        Car();
        Car(std::istream&);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream&) const;
        ~Car(){}
        

    };
    //helpers
    void eraseStr(std::string&);

}



#endif

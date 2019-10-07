// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Reservation.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <utility>

#ifndef RESTAURANT_H
#define RESTAURANT_H


namespace sdds{

    class Restaurant{

        Reservation *res; 
        size_t numRes;

        public:

        Restaurant();
        Restaurant(Reservation* rezzy[], size_t cnt);
        Restaurant(Restaurant&);
        Restaurant(Restaurant&&);
        ~Restaurant();
        Restaurant& operator=(const Restaurant&);
        Restaurant& operator=(Restaurant&&); //cannot be const;
        size_t size() const;
        friend std::ostream& operator<<(std::ostream&, const Restaurant&);
    
    };

}

#endif

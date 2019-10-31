// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef AUTOSHOP_H
#define AUTOSHOP_H

#include <vector>
#include <algorithm>
#include "Vehicle.h"

namespace sdds{


    class Autoshop{
        std::vector<Vehicle*> m_vehicles;

        public:
        Autoshop& operator +=(Vehicle*);
        void display(std::ostream&) const;
    };
}
#endif

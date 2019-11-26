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
#include <list>

namespace sdds{


    class Autoshop{
        std::vector<Vehicle*> m_vehicles;

        public:
        Autoshop& operator +=(Vehicle*);
        void display(std::ostream&) const;
        ~Autoshop();
        template<class T>
        void select(T test, std::list<const Vehicle*>& vehicles)
        {
            std::vector<Vehicle*>::iterator iter;
            for(iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++){
                if(test(*iter)){
                    vehicles.push_back(*iter);
                }
            }
        }

        /*- `void select(T test, std::list<const Vehicle*>& vehicles)`: a **template** function 
        that iterates over the vehicles stored in the `m_vehicles`, and adds to the second parameter 
        all vehicles for which the `test` is true. The first parameter (`test`) can be a lambda 
        expression, a pointer to a function, or a functor that matches the prototype:
        ```
        bool func(const sdds::Vehicle*);
        ```*/
    };
}
#endif

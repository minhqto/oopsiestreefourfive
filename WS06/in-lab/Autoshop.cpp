// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Autoshop.h"

namespace sdds
{
    Autoshop& Autoshop::operator+=(Vehicle *theVehicle)
    {
        m_vehicles.push_back(theVehicle);
       
        
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;
        std::vector<Vehicle*>::const_iterator iter;
       
        for(iter = m_vehicles.cbegin(); iter != m_vehicles.cend(); iter++){
            (*iter)->display(out);
            //out << *(*iter) << std::endl;
        }
        out << "--------------------------------" << std::endl;

    }
}
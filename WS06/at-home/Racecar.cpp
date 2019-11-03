// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds
{
    Racecar::Racecar() : Car()
    {
        m_booster = 0;
    }

    Racecar::Racecar(std::istream& in) : Car(in)
    {
        std::string tempBoost;
        in.seekg(std::ios::beg);
        std::getline(in, tempBoost);

        while(tempBoost.find(' ') != std::string::npos)
        {
            tempBoost.erase(tempBoost.find(' '), 1);
        }
        m_booster = std::stod(tempBoost.substr(tempBoost.find_last_of(',') + 1));
    }   

    void Racecar::display(std::ostream& out) const
    {
        this->Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return this->Car::topSpeed() * (1 + m_booster);
    }


}
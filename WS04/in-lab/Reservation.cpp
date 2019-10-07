// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Reservation.h"

namespace sdds
{
    Reservation::Reservation()
    {
        resId = "";
        name = "";
        email = "";
        numParty = 0;
        day = 0;
        hour = 0;
    }

    Reservation::Reservation(const std::string& m_res) 
    {
        std::string tempString = m_res;
        while(tempString.find(' ') != std::string::npos){
            unsigned int indexer = tempString.find(' ');
            tempString.erase(indexer, 1); //this erase looks at the index, declared in the first argument
                                            //and erases just 1 character, declared in the second argument
        }
        //resId
        unsigned int posSpace = tempString.find(":"); //returns an index
        resId = tempString.substr(0, posSpace);
        //name
        unsigned int posFirstComma = tempString.find(",");
        unsigned int endOfName = posFirstComma - posSpace;
        name = tempString.substr(posSpace + 1, endOfName - 1);

        //email
        unsigned int posSecondComma = tempString.find(",", posFirstComma + 1);
        unsigned int endOfEmail = posSecondComma - posFirstComma;
        email = tempString.substr(posFirstComma + 1, endOfEmail - 1);

        //numParty
        unsigned int posThirdComma = tempString.find(",", posSecondComma + 1);
        unsigned int endOfParty = posThirdComma - posSecondComma;
        numParty = std::stoi(tempString.substr(posSecondComma + 1, endOfParty - 1));
        
        //day
        unsigned int posFourthComma = tempString.find(",", posThirdComma + 1);
        unsigned int endOfDay = posFourthComma - posThirdComma;
        day = std::stoi(tempString.substr(posThirdComma + 1, endOfDay - 1));
        
        //hour
        hour = std::stoi(tempString.substr(posFourthComma + 1));   
    }

    Reservation::~Reservation(){}

    void Reservation::display(std::ostream& os) const
    {
        os << "Reservation " << resId << ": ";
            os << std::setw(10);
            os.setf(std::ios::right);
            os << name;
            os.unsetf(std::ios::right); 
            os << "  ";
            os.setf(std::ios::left);
            os << std::setw(24) << "<" + email + ">";

        if(hour >= 6 && hour <= 9 ){
            os << " " << "Breakfast on day " << day
            << " @ " << hour << ":00 " << "for " << numParty << " people." << std::endl;
        }

        else if(hour >= 11 && hour <= 15 ){
            os << " " << "Lunch on day " << day
            << " @ " << hour << ":00 " << "for " << numParty << " people." << std::endl;
        }

        else if(hour >= 17 && hour <= 21 ){
            os << " " << "Dinner on day " << day
            << " @ " << hour << ":00 " << "for " << numParty << " people." << std::endl;
        }
        else{
            os << " " << "Drinks on day " << day
            << " @ " << hour << ":00 " << "for " << numParty << " people." << std::endl;
        }
    }
    std::ostream& operator<<(std::ostream& os, const Reservation& src)
    {
        src.display(os);
        return os;
    }
}

/*int main()
{
    std::string testString = "RES-001: John    ,  john@email.com  ,           2,   3,    5";
    sdds::Reservation test(testString);
    std::cout << test;
}*/


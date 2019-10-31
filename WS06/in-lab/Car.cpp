// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"

namespace sdds
{
    Car::Car()
    {
        maker = "";
        carCondition = "";
        top_speed = 0;
    }
    Car::Car(std::istream& src)
    {
        std::string tempCar;
        std::getline(src, tempCar); 
       
        //need to erase spaces
        while(tempCar.find(' ') != std::string::npos){
            size_t indexer = tempCar.find(' ');
            tempCar.erase(indexer, 1);
        }
        
        eraseStr(tempCar);
        maker = tempCar.substr(0, tempCar.find_first_of(','));

        eraseStr(tempCar);
        carCondition = tempCar.substr(0, tempCar.find_first_of(','));
        if(carCondition == "n"){
            carCondition = "new";
        }
        else if(carCondition == "b"){
            carCondition = "broken";
        }

        eraseStr(tempCar);  
        top_speed = std::stoi(tempCar);


    }
    std::string Car::condition() const
    {
        return carCondition;
    }

    double Car::topSpeed() const
    {   
        return top_speed;
    }
    void Car::display(std::ostream& out) const
    {
        out << "|";
        out.width(10);
        out << this->maker;
        out << " | ";
        out.width(7); 
        out.setf(std::ios::left);
        out << this->carCondition;
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(6);
        out.setf(std::ios::fixed);
        out.precision(2);
        out << this->top_speed << " |";
        out.unsetf(std::ios::fixed);
        out << std::endl;
    }
        
    void eraseStr(std::string& src)
    {
        size_t comma = src.find_first_of(',');
        src.erase(0, comma + 1);
    }
}


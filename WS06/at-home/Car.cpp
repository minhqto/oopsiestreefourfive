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
        //c,176
        
        eraseStr(tempCar);
        carCondition = tempCar.substr(0, tempCar.find_first_of(','));
        if(carCondition == ""){
            carCondition = "new";
        }
        else if(carCondition == "n"){
            carCondition = "new";
        }
        else if(carCondition == "b"){
            carCondition = "broken";
        }
        else if(carCondition == "u"){
            carCondition = "used";
        }
        else{
            throw "Invalid record! 3";
        }
        
        /*the token representing the condition of the car is a different character than `n`, `u`, or `b`:
        - generate an exception to inform the client that this record is invalid*/

        //top speed
        //246, 0.2
        eraseStr(tempCar);
        if(tempCar.find_first_of(',') != std::string::npos){
                top_speed = std::stoi(tempCar.substr(0, tempCar.find_first_of(',')));
        }
        else{
            eraseStr(tempCar); 
                top_speed = std::stoi(tempCar);
        }   
        

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
        out.width(11);
        out << this->maker;
        out << " | ";
        out.width(6); 
        out.setf(std::ios::left);
        out << this->condition();
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(6);
        out.setf(std::ios::fixed);
        out.precision(2);
        out << this->topSpeed() << " |";
        out.unsetf(std::ios::fixed);
    }
        
    void eraseStr(std::string& src)
    {
        size_t comma = src.find_first_of(',');
        src.erase(0, comma + 1);
    }
}


// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 31 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"
#include "Car.h"

namespace sdds
{
    Vehicle* createInstance(std::istream& in)
    {
   
        //the ss object allows you to treat a string object like a stream 
        //since the Car constructor only takes in an istream object 
        //if you pass in the entire in object, because createInstance read the first 
        //line of the file, the Car constructor can only end up reading the second line 
        //and then createInstance reads the third line. We want to pass the file line by line to the Car construtor
         //a pointer that holds other pointers
        
        do{
            Car* newCarPtr = nullptr;
            std::string tempVeh;
            std::getline(in, tempVeh);
            
            if(in){
                if(tempVeh[0] == 'C' || tempVeh[0] == 'c'){
                    
                    std::stringstream ss(tempVeh);
                    
                    Car newCar(ss);
                    newCarPtr = &newCar;
                    
                }
            }
            return newCarPtr;

        }while(in);

        
    }
}

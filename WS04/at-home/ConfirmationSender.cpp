// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        allRezzies = nullptr;
        size = 0;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender& src)
    {
        if(this->allRezzies != nullptr){ 
            this->allRezzies = nullptr;
        }
        *this = src;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
    {
        *this = std::move(src);
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
    {
        if(this != &src){
            delete [] this->allRezzies;
            this->allRezzies = new const Reservation*[src.size];
            for(size_t i = 0; i < src.size; i++){
                this->allRezzies[i] = src.allRezzies[i];
            }
            this->size = src.size;
        }
        else{
            this->allRezzies = nullptr;
            this->size = 0;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
    {
        if(this != &src){
            delete [] this->allRezzies;
            this->size = src.size;
            this->allRezzies = src.allRezzies;
            src.allRezzies = nullptr;
            src.size = 0u;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete [] allRezzies;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool isEqual = false;
        for(size_t i = 0; i < this->size; i++){
            if(this->allRezzies[i] == &res){
                isEqual = true;
            }
        }
        if(isEqual == false){
            //copy old array into temp object
            const Reservation* *temp = new const Reservation*[this->size];
            for(size_t i = 0; i < this->size; i++){
                temp[i] = this->allRezzies[i];
            }
            // add memory to allRezzies by one
            this->size += 1;
            //delete [] this->allRezzies;
            this->allRezzies = new const Reservation*[this->size];
            //this takes an address of a reservation. our array holds pointers of type reservations
            for(size_t i = 0; i < this->size; i++){
                this->allRezzies[i] = temp[i];
            }
            this->allRezzies[this->size - 1] = &res;
        }  
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        for(size_t i = 0; i < this->size; i++){
            if(this->allRezzies[i] == &res){
                this->allRezzies[i] = nullptr;
            }
        }
       return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src)
    {       
        
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if(src.size == 0){
            os << "The object is empty!" << std::endl;  
        }
        else{
            for(size_t i = 0; i < src.size; i++){
                if(src.allRezzies[i] != nullptr){
                    os << *(src.allRezzies[i]);
                }
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}

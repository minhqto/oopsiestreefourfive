// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds{

        Restaurant::Restaurant()
        {
            res = nullptr;
        }

        Restaurant::Restaurant(Reservation* rezzy[], size_t cnt)
        {
            res = nullptr;
            res = new Reservation[cnt]; //allocate enough memory for res
            numRes = cnt;
            for(size_t i = 0; i < cnt; i++){
                res[i] = *rezzy[i]; //needs to copy over the pointers themselves
            }
        
        }
        Restaurant::Restaurant(Restaurant& src)
        {
            this->res = nullptr;
            *this = src;
        }
       
        Restaurant::Restaurant(Restaurant&& src)
        {
            this->res = nullptr;
            *this = std::move(src);
        }
        Restaurant& Restaurant::operator=(const Restaurant& src)
        {
            if(this != &src){
                this->numRes = src.numRes;
                if(this->res != nullptr){
                    delete [] res;
                }
                this->res = new Reservation[src.size()];
                for(size_t i = 0; i < src.size(); i++){
                    this->res[i] = src.res[i];
                }
            }
            else{
                this->res = nullptr;
                this->numRes = 0;
            }
            return *this;
        }
        Restaurant& Restaurant::operator=(Restaurant&& src)
        {
            //check for self assignment
            if(this != &src){
                //copy non-resource members
                this->numRes = src.numRes;
                //move data over
                this->res = src.res;
                //set the src data to default values
                src.res = nullptr;
                src.numRes = 0;
            }
            return *this;
        }

        Restaurant::~Restaurant()
        {
            delete [] res;
        }

        size_t Restaurant::size() const
        {
            return numRes;
        }

        std::ostream& operator<<(std::ostream& os, const Restaurant& src)
        {
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant" << std::endl;
            os << "--------------------------" << std::endl;
            if(src.numRes > 0){
                for(size_t i = 0; i < src.numRes; i++){
                    os << src.res[i];
                }
            }
            else{
                os << "The object is empty!" << std::endl;
            }
            os << "--------------------------" << std::endl;
            return os;
        }

}

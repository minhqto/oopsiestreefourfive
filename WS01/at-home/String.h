// Name: Minh To 
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 11 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

namespace sdds
{
    extern unsigned int g_maxSize; //have to use the keyword external so string.cpp knows this global variable exists

    class String{
        char* str = nullptr;

        public: 

        String(const char*);
        String(const String&);      //a copy constructor & assignment op overload is needed because without that, 
                                    //the deconstructor will delete the memory allocated to *str, 
                                    //and if the pointer of the obj to be copied is not allocated elsewhere properly, the
                                    //program throws a malloc error. 
        String& operator=(const String&);
        ~String();
        void display(std::ostream&) const;

    };
    std::ostream& operator<<(std::ostream&, const sdds::String&);
    

}

#endif

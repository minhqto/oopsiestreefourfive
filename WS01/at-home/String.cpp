// Name: Minh To 
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 11 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "String.h"

unsigned int sdds::g_maxSize = 3;

sdds::String::String(const char *src)
{
    if(src != nullptr){

        str = new char[g_maxSize];
        strncpy(str, src, g_maxSize);
        str[g_maxSize] = '\0'; //have to subtract one because main annoyingly adds one to 
                                        //global variable g_maxSize, increasing it to 4
    }
    else{
        strncpy(str, "", 1);
        str[1] = '\0';
    }
}

sdds::String::~String()
{
    delete [] str;
}

sdds::String::String(const String& src)
{
    *this = src;
}

sdds::String& sdds::String::operator=(const sdds::String& src)
{
    if(this != &src){
        delete [] str;
        str = new char[g_maxSize];
        strncpy(str, src.str, g_maxSize);
    }
    else{
        this->str = nullptr;
    }

    return *this;
}

void sdds::String::display(std::ostream& w) const
{
    w << this->str;
}


std::ostream& sdds::operator<<(std::ostream& os, const sdds::String& src)
{
    static unsigned int count = 0;
    std::cout << count + 1 << ". ";
    count++;
    src.display(os);
    return os;
}
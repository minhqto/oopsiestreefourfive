// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <fstream>
#include <array>

namespace sdds{
class Text{
        unsigned long long int numStr = 0;
        std::string *s;
    public:

        Text();
        Text(std::string);
        Text(Text&);
        Text& operator=(const Text&);
        Text(Text&&); //move constructor
        Text& operator=(Text&&); //move assignment operator
        ~Text();
        size_t size() const;
    };

}
#endif

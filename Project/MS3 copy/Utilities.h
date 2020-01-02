// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Nov 19
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>
#include <sstream>


class Utilities{

    size_t m_widthField{1};
    static char m_delimiter;

    public:

    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string&, size_t&, bool&);
    static void setDelimiter(const char);
    char getDelimiter() const;

};

#endif

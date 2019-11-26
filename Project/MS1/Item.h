// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Nov 19
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
#include "Utilities.h"

class Item{

    std::string m_name;
    std::string m_description;
    size_t m_serialNumber;
    size_t m_quantity;
    static size_t m_widthField;

    public:
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream&, bool) const;

};

#endif

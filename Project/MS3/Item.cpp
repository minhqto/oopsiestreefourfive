// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Nov 19
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;

Item::Item(const std::string &src)
{
    Utilities uObj;
    std::string tempSrc = src;
    //size_t nextPos = src.find(uObj.getDelimiter());
    bool more = true;
    size_t nextPos = 0;
    m_name = uObj.extractToken(tempSrc, nextPos, more);
    tempSrc.erase(0, tempSrc.find(uObj.getDelimiter())+1); //position of next delimier
    m_serialNumber = std::stoi(uObj.extractToken(tempSrc, nextPos, more));
    tempSrc.erase(0, tempSrc.find(uObj.getDelimiter())+1);
    m_quantity = std::stoi(uObj.extractToken(tempSrc, nextPos, more));
    tempSrc.erase(0, tempSrc.find(uObj.getDelimiter())+1);
    m_description = uObj.extractToken(tempSrc, nextPos, more);
    if(m_name.length() > m_widthField){
        m_widthField = m_name.length();
    }


}

//`const std::string& getName() const` - returns the name of the current `Item` object
const std::string& Item::getName() const
{
    return m_name;
}
//`const unsigned int getSerialNumber()` – returns the next serial number to be used on the assembly line and increments `m_serialNumber`

const unsigned int Item::getSerialNumber()
{
    return m_serialNumber++;
}

//`const unsigned int getQuantity()` – returns the remaining quantity of the current `Item` object

const unsigned int Item::getQuantity()
{
    return m_quantity;
}

//-  `void updateQuantity()` – substracts 1 from the available quantity; should not go below 0.

void Item::updateQuantity()
{
    if(m_quantity > 0){
        m_quantity--;
    }
}

void Item::display(std::ostream& os, bool full) const
{
    if(!full){
        os.setf(std::ios::left);
        os.width(m_widthField);
        os << m_name;
        os.unsetf(std::ios::left);
        os.setf(std::ios::right);
        os << " [";
        os.width(6);
        os.fill('0');
        os << m_serialNumber << "]" << std::endl;
        os.fill(' ');
        os.unsetf(std::ios::right);
    }
    else{
        os.setf(std::ios::left);
        os.width(m_widthField);
        os << m_name;
        os.unsetf(std::ios::left);
        os.setf(std::ios::right);
        os << " [";
        os.width(6);
        os.fill('0');
        os << m_serialNumber << "] ";
        os.fill(' ');
        os.unsetf(std::ios::right);
        os << "Quantity: ";
        os.setf(std::ios::left);
        os.width(m_widthField);
        os << m_quantity;
        //os.width(m_widthField);
        os.fill(' ');
        os.setf(std::ios::right);
        os << "Description: " << m_description << std::endl;
        os.unsetf(std::ios::right);
    }
}



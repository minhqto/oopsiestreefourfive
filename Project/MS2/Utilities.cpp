// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Nov 19
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t fw)
{
    m_widthField = fw;
}

size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}

/*extracts tokens from the first parameter
  - This function uses the delimiter to extract the next token from `str` starting at `next_pos`.
  - If successful, it returns the extracted token found and sets `more` to `true`; `false` otherwise.
  - This function reports an exception if there are two delimiters with no token between them.
  - This function updates the current object's `m_widthField` data member if its current value is less than the size of the token extracted.
    - **Note:**  `str` represents a single line read from an input file.*/

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    std::stringstream ss(str.substr(next_pos));
    std::string strToken;
    try{
        std::getline(ss, strToken, m_delimiter);
        if(strToken[0] == ' ' || strToken.length() == 0){
            more = false;
            throw "No token was found!";
        }
        else{
            if(m_widthField < strToken.length()){
                m_widthField = strToken.length();
            }
            more = true;

        }
    }
    catch(const char* msg){
        std::cout << msg << std::endl;
    }
    return strToken;
}

void Utilities::setDelimiter(const char d)
{
    m_delimiter = d;
}
char Utilities::getDelimiter() const
{
    return m_delimiter;
}

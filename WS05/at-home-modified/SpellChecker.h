// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 9 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

namespace sdds{

    class SpellChecker{
        std::string m_badWords[5];
        std::string m_goodWords[5];

        public:
        SpellChecker(const char*);
        void operator()(std::string&);
    
    };

}


#endif

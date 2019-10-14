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

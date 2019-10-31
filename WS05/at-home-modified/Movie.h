// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 9 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef MOVIE_H
#define MOVIE_H


#include <string>
#include "SpellChecker.h"


namespace sdds{
    
    class Movie{
        std::string mTitle;
        size_t yearRelease;
        std::string desc;

        public:

        Movie();
        Movie(const std::string&);
        const std::string& title() const;
        template<typename T>
        void fixSpelling(T spellchecker){
            spellchecker(mTitle);
            spellchecker(desc);
        }
        friend std::ostream& operator<<(std::ostream&, const Movie&);
    };

    std::string& m_removeSpace(std::string&);
    bool m_checkForSpacesAfter(const std::string&);
    std::string m_grabSubString(const std::string&);
    void m_modifyStringRemainder(std::string&, std::string&);
}


#endif

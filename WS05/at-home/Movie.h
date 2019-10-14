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

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 9 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

//[capture list](parameters){optional function body}

#include <iostream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"

#ifndef BOOK_H
#define BOOK_H

namespace sdds

{
    class Book{

        std::string author;
        std::string bTitle;
        std::string countryPub;
        int yearPub;
        double bookPrice;
        std::string summary;

        public:

        Book();
        Book(const std::string&);
        const std::string& title() const;
        const std::string& country() const;
        const int& year() const;
        double& price();
        
        template<typename T>
        void fixSpelling(T spellchecker){
            spellchecker(summary);
        }
        
        friend std::ostream& operator<<(std::ostream&, const Book&);


    };
    //helper
    std::string& removeSpace(std::string&);
    bool checkForSpacesAfter(const std::string&);
    std::string grabSubString(const std::string&);
    void modifyStringRemainder(std::string&, std::string&);
}

#endif

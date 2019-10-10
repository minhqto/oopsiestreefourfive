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

#ifndef BOOK_H
#define BOOK_H

namespace sdds

{
    template<class T>
    class Book{

        std::string author;
        std::string title;
        std::string countryPub;
        unsigned int yearPub;
        float price;
        std::string summary;

        public:

        Book();
        Book(const std::string&);
        const std::string& title() const;
        const std::string& country() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();

        friend std::ostream& 


    };

}






#endif

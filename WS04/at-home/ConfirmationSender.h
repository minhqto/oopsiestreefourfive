// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 1 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include "Reservation.h"

#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

namespace sdds{

    class ConfirmationSender{

        const Reservation** allRezzies; //allRezzies will be a dynamically allocated array has that pointers of type reservation
        size_t size;

        public:

        ConfirmationSender();
        //ConfirmationSender(Reservation*&);
        ConfirmationSender(ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&);
        ~ConfirmationSender();
        ConfirmationSender& operator=(const ConfirmationSender&);
        ConfirmationSender& operator=(ConfirmationSender&&);
        ConfirmationSender& operator+=(const Reservation&);
        ConfirmationSender& operator-=(const Reservation&);
        friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);

    };


}




#endif

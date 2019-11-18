#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 18 Nov 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif
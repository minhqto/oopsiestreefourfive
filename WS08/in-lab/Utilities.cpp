// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 13 Nov 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"
#include <algorithm>

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList; //a list of products (from the element.h)

		// TODO: Add your code here to build a list of products
		/*
		 * Your Task: Implement the mergeRaw() function. This function compares the elements
		 * in the two received lists for common product codes and builds the user-friendly
		 * list from the matching pairs. For each successful comparison, your function allocates
		 * dynamic memory of Product type using that description and the price. Your function then
		 * validates the Product object and adds it to its list. Your function returns a copy of this list.
		 * */
        //check that the first element in the desc list matches the first element in price, and so on

            for(size_t i = 0; i < desc.size(); i++){
                for(size_t k = 0; k < price.size(); k++) {
                    if (desc[i].code == price[k].code) {
                        Product *p = new Product(desc[i].desc, price[k].price);
                        p->validate();
                        priceList += p;
                        delete p;
                    }
                }
            }
		return priceList;
	}
}
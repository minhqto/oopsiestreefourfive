// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 18 Nov 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

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

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

        for(size_t i = 0; i < desc.size(); i++){
            for(size_t k = 0; k < price.size(); k++) {
                if (desc[i].code == price[k].code) {
                    std::shared_ptr<Product> p(new Product(desc[i].desc, price[k].price));
                    p->validate();
                    priceList += p;
                }
            }
        }


		return priceList;
	}
}
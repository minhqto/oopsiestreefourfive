// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"
#include <cmath>
using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	
		// get the books
		sdds::Book library[7]; //array of book items
		std::string aBook; //empty string
		std::ifstream bookFile(argv[1]);
		size_t lines = 0;
		
		if(!bookFile){
			std::cerr << "File of books is not found!" <<std::endl; 
			return 1;
		}

		do {

			std::getline(bookFile, aBook);
			if(bookFile){
				if(aBook[0] != '#'){
					library[lines] = sdds::Book(aBook);
					lines++;
				}
			}

		} while(bookFile);

		bookFile.clear();
		bookFile.seekg(std::ios::beg);

		


		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
	
	
	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	
	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto updatePrice = [=](sdds::Book& src){
		
		if(src.country() == "US"){
			src.price() *= usdToCadRate;
			src.price() *= 100;
			src.price() = floor(src.price());
			src.price() /= 100;
		}
		else if(src.country() == "UK" && src.year() >= 1990 && src.year() <= 1999){
			src.price() *= gbpToCadRate;
			src.price() *= 100;
			src.price() = floor(src.price());
			src.price() /= 100;
		}

		//had to do this because precision was not working in my output
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for(auto& book: library){
		updatePrice(book);
	}
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}

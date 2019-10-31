// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 9 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"
#include <math.h>
#include <stdexcept>

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored
		
		std::ifstream bookFile(argv[1]);
		std::string tempBookGetter;
		size_t lineCount = 0;
		if(!bookFile){
			std::cerr << "File of books is not found!" <<std::endl; 
			return 1;
		}
		
		do
		{	
			std::getline(bookFile, tempBookGetter);
			if(bookFile.good()){
				if(tempBookGetter[0] != '#'){
					library += tempBookGetter;
					lineCount++;
					
				}
			}
			
		} while(bookFile.good() && lineCount < 4);
	
		// TODO: add the rest of the books from the file.
		do
		{	
			library.setObserver(bookAddedObserver);
			std::getline(bookFile, tempBookGetter);
			if(bookFile.good()){
				if(tempBookGetter[0] != '#'){
					library += tempBookGetter;
				}
			}
		} while(bookFile.good());
		bookFile.clear();
		bookFile.seekg(std::ios::beg);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
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
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for(size_t i = 0; i < library.size(); i++){
		updatePrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream movieFile(argv[2]);
		std::string tempMovieGetter;
		size_t movieIdxr = 0;
		if(!movieFile){
			std::cerr << "File of movies is not found!" <<std::endl; 
			return 1;
		}
		do
		{	
			std::getline(movieFile, tempMovieGetter);
			if(movieFile.good()){
				if(tempMovieGetter[0] != '#'){
					movies[movieIdxr] = sdds::Movie(tempMovieGetter);
					movieIdxr++;
				}
			}
		} while(movieFile.good());

		movieFile.clear();
		movieFile.seekg(std::ios::beg);
	
	}
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	// Add a few movies to collection; no observer is set
	((theCollection += movies[0]) += movies[1]) += movies[2];
	theCollection += movies[1];
	// add more movies; now we get a callback from the collection
	theCollection.setObserver(movieAddedObserver);
	theCollection += movies[3];
	theCollection += movies[3];
	theCollection += movies[4];
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		try{
			for (auto i = 0u; i < 10; ++i) {
				std::cout << theCollection[i];
			}
		}catch(const std::out_of_range& msg){
			std::cerr << "EXCEPTION: " << msg.what() << std::endl;
		}
		

	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
			// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.
			try{
				SpellChecker sp(argv[i]);
				for (auto j = 0u; j < theCollection.size(); ++j)
					theCollection[j].fixSpelling(sp);
				for (auto j = 0u; j < library.size(); ++j)
					library[j].fixSpelling(sp);
			}catch(const char *msg){
				std::cout << "EXCEPTION: " << msg << std::endl;
			}
	}
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}

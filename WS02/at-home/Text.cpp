// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 17 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Text.h"
namespace sdds
{
    Text::Text()
    {
        s = nullptr;
        numStr = 0;
    }

    Text::Text(std::string src)
    {
        std::string eater;
        std::fstream fin;
        fin.open(src);
        unsigned int i = 0;

        if(!fin.is_open()){
            std::cout << "File error!";
        }
        while(fin.good()){
            if(std::getline(fin, eater, ' ')){ //if current character is space
                numStr++;
            };
        }
        fin.seekg(std::ios::beg); //sets the file pointer back to the beginning
        s = new std::string[numStr];
        
        while(fin.good()){
            std::getline(fin, s[i], ' ');
            i++;
        }
        numStr--;
        fin.close();
    }

    Text::~Text()
    {
        delete [] s;
    }

    Text::Text(Text& src)
    {
        *this = src;
    }
    Text& Text::operator=(const Text& src)
    {
        if(this != &src){
            this->numStr = src.numStr;
            delete [] s;
            this->s = new std::string[src.numStr];
            for(unsigned int i = 0; i < numStr; i++){
                this->s[i] = src.s[i];
            }
        }
        else{
            this->s = nullptr;
        }
        return *this;
    }

    Text::Text(Text&& src)
    {
        *this = std::move(src); //you have to use std::move because this function will make src a rvalue, which calls the 
                                //assignment operator that takes an rvalue instead of the one that takes an lvalue
    }

    Text& Text::operator=(Text&& src)
    {
        if(this != &src){
            this->numStr = src.numStr;
            this->s = src.s;
            src.s = nullptr;
            src.numStr = 0;
        }else{
            this->s = nullptr;
        }

        return *this;
    }

    size_t Text::size() const 
    {
        return numStr;
    }
}
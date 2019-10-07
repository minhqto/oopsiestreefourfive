// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca    
// Date of completion: 25 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <array>


namespace sdds
{
    template<class T, unsigned int maxElArr>
    class List
    {
        T anyEl[maxElArr];
        unsigned int counter = 0;

        public: 
        
        size_t size() const
        {
            return counter;
        }    

        const T& operator[](size_t i) const
        {
            return anyEl[i];
        }

        void operator+=(const T& tt)
        {
            unsigned int arrSize = this->size();
            if(arrSize < maxElArr){
                anyEl[arrSize] = tt;
                counter++;
            }
        }
    };

	/*
	L: the type of a label
	V: the type summation value
	T: the type of any element in the collection	
	N: the maximum number of elements in the collection (an integer without sign)*/

	template<class L, class V, class T, unsigned int maxElArr>
	class LVList : public List<T, maxElArr>
	{
		L labelType;
		V sumValue; 

	public:
		
		V accumulate(const L& label) const
		{
			V accumulator;
			SummableLVPair<L, V> temp;
			accumulator = temp.getInitialValue();
			for (unsigned int i = 0; i < this->size(); i++) {
				temp = (*this)[i];
				if (temp.key() == label) {
					accumulator = (*this)[i].sum(label, accumulator);
				}
			}
			return accumulator;
		}
	};
	
}

#endif

// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 9 Oct 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
#include <iostream>
#include <stdexcept>

namespace sdds{

    template<class T>
    class Collection{

        std::string collectionName;
        T *collectionItems;
        size_t sizeArr;
        void (*addItemObserver)(const Collection<T>&, const T&) = nullptr; //Collection<T> tells us what the data type of the collection object is
        public:
        Collection() : collectionName(""), collectionItems(nullptr), sizeArr(0){}

        ~Collection()
        {
            delete [] collectionItems;
        }

        Collection(std::string name){
            collectionName = name;
            collectionItems = nullptr;
            sizeArr = 0;
        }

        Collection(Collection&) = delete;

        Collection& operator=(const Collection&) = delete;

        const std::string& name() const
        {
            return collectionName;
        }

        size_t size() const
        {
            return sizeArr;
        }

        ///this gets passed back a function
            /*stores the parameter into an attribute, to be used when an item is added to the 
            collection. The parameter is a pointer to a function that returns void 
            and accepts two parameters: a collection and an item that has just been added to the 
            collection*/
        void setObserver(void (*observer) (const Collection<T>& cItem, const T& anItem))
        {
            addItemObserver = observer;
        }

        /*adds a copy of item to the collection, only if the collection doesn't contain an 
            item with the same title (type T has a member function called title() that returns the 
            title of the item). If item is already in the collection, this function does nothing. 
            If the item is not already in the collection, this function:

            resize the array to accomodate the new item
            if there is an observer registered, call the observer function passing *this 
            and the new item as parameters.*/
        Collection<T>& operator+=(const T& item)
        {
			
            bool sameTitle = false;
            if(sizeArr == 0){
                    sizeArr++;
                    collectionItems = new T[sizeArr];
                    collectionItems[0] = item; 
            } 
            else if(sizeArr > 0){
                for(size_t i = 0; i < sizeArr; i++){
                    if(item.title() == collectionItems[i].title()){
                        sameTitle = true;
                    }
                }
                if(sameTitle == false){
                    T *tempCollectionItems = new T[sizeArr];
                    for(size_t i = 0; i < sizeArr; i++){
                        tempCollectionItems[i] = collectionItems[i];
                    }
                    sizeArr++;

                    collectionItems = new T[sizeArr];
                    for(size_t i = 0; i < sizeArr - 1; i++){
                        collectionItems[i] = tempCollectionItems[i];
                    }
                    collectionItems[sizeArr - 1] = item;
                    
					if (addItemObserver != nullptr) {
						addItemObserver(*this, item);
					}
                }
                 else{
                    //don't add
                }
            }
            return *this;
            
        }
        /*
        returns the item at index
        if the index is out of range, this function throws an exception of type std::out_of_range
        with the message Bad index [IDX]. Collection has [SIZE] items.. Use operator + to 
        concatenate strings.*/
        T& operator[](size_t idx) const
        {
			
				if (idx >= sizeArr) {
					std::string idexStr = std::to_string(idx);
					std::string sizeStr = std::to_string(sizeArr);
					throw std::out_of_range("Bad index [" + idexStr + "]. Collection has [" + sizeStr + "] items.");
				}
				else {
					return collectionItems[idx];
				}
        }
            /*returns the address of the item with title title 
            (type T has a member function called title() that returns the title of the item). 
            If no such item exists, this function returns nullptr.*/
        T* operator[](std::string title) const
        {
            T *addrOrNullptr = nullptr;
            for(size_t i = 0; i < sizeArr; i++){
                if(collectionItems[i].title() == title){
                    addrOrNullptr = &collectionItems[i];
                }
            }
            return addrOrNullptr;
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& src)
    {	
        for(size_t i = 0; i < src.size(); i++){
            os << src[i]; //need to fix this
        }
        return os;
    }
}

#endif

#include "Book.h"

namespace sdds
{
        Book::Book()
        {
            author = "";
            bTitle = "";
            countryPub = "";
            yearPub = 0;
            bookPrice = 0;
            summary = "";
        }
        Book::Book(const std::string& strBook)
        {
            std::string tempStrBook = strBook;

            author = grabSubString(tempStrBook);
            modifyStringRemainder(tempStrBook, author);
            removeSpace(tempStrBook);

            //get title
            bTitle = grabSubString(tempStrBook);
            modifyStringRemainder(tempStrBook, bTitle);
            removeSpace(tempStrBook);

            //get country of publication
            countryPub = grabSubString(tempStrBook);
            modifyStringRemainder(tempStrBook, countryPub);
            removeSpace(tempStrBook);

            //get price 
            std::string priceAsString;
            priceAsString = grabSubString(tempStrBook);
            modifyStringRemainder(tempStrBook, priceAsString);
            bookPrice = std::stof(priceAsString);
            removeSpace(tempStrBook);

            //get pub year
            std::string tempPubYear;
            tempPubYear = grabSubString(tempStrBook);
            modifyStringRemainder(tempStrBook, tempPubYear);
            yearPub = std::stoi(tempPubYear);
            removeSpace(tempStrBook);

            //get summary
            summary = tempStrBook;
        }

        std::string grabSubString(const std::string& src)
        {
            std::string sub;
            sub = src.substr(0, src.find(',') + 1);
            return sub;
        }
        
        //1) takes full string and substring, removes substring from full string
        //2) check for spaces between comma and final letter in the substring
        //3) erases those spaces
        //4) erases the comma at the end.
        void modifyStringRemainder(std::string& fullStr, std::string& subStr){
            fullStr.erase(0, fullStr.find(',') + 1);
            while(checkForSpacesAfter(subStr)){
                subStr.erase(subStr.find_last_of(' '), 1);
            };
            subStr.erase(subStr.find_last_of(','));
        }

        //remove space helper function
        std::string& removeSpace(std::string& src)
        {
             while(isspace(src[0])){
                src.erase(0, 1);
            }
            return src;
        }
        bool checkForSpacesAfter(const std::string& src)
        {  
            bool check = false;
            if(isspace(src[src.find_last_of(',') - 1])){
                check = true;
            }
            return check;
        }

        const std::string& Book::title() const
        {
            return bTitle;
        }
        const std::string& Book::country() const
        {
            return countryPub;
        }
        const int& Book::year() const
        {
            return yearPub;
        }
        double& Book::price()
        {
            return bookPrice;
        }

        std::ostream& operator<<(std::ostream& os, const Book& src)
        {   
            os.setf(std::ios::right);
            os << std::setw(20) << src.author << " | ";
            os << std::setw(22) <<src.bTitle << " | ";
            os << std::setw(5) <<src.countryPub << " | ";
            os << std::setw(4) <<src.yearPub << " | ";
            os << std::setw(6);
            os.unsetf(std::ios::right);
            os.setf(std::ios::fixed);
            os.precision(2);
            os <<src.bookPrice << " | ";
            os.unsetf(std::ios::right);
            os << src.summary;
            os << std::endl;
            return os;
        }
}


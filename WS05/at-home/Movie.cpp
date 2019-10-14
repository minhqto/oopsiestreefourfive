#include "Movie.h"

namespace sdds
{
    Movie::Movie() : mTitle(""), yearRelease(0), desc(""){}

    Movie::Movie(const std::string& src)
    {
        std::string tempMovieStr = src;

        mTitle = m_grabSubString(tempMovieStr);
        m_modifyStringRemainder(tempMovieStr, mTitle);
        m_removeSpace(tempMovieStr);

        //get yearRelease;
        std::string tempRelYear;
        tempRelYear = m_grabSubString(tempMovieStr);
        m_modifyStringRemainder(tempMovieStr, tempRelYear);
        yearRelease = std::stoi(tempRelYear);
        m_removeSpace(tempMovieStr);

        desc = tempMovieStr;
    }
    const std::string& Movie::title() const
    {
        return mTitle;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& src)
    {
        os << std::setw(40) << src.mTitle;
        os << std::setw(4) << src.yearRelease;
        os << src.desc;
        return os;
    }

    std::string m_grabSubString(const std::string& src)
        {
            std::string sub;
            sub = src.substr(0, src.find(',') + 1);
            return sub;
        }

        void m_modifyStringRemainder(std::string& fullStr, std::string& subStr){
            fullStr.erase(0, fullStr.find(',') + 1);
            while(m_checkForSpacesAfter(subStr)){
                subStr.erase(subStr.find_last_of(' '), 1);
            };
            subStr.erase(subStr.find(','));
        }

        //remove space helper function
        std::string& m_removeSpace(std::string& src)
        {
             while(isspace(src[0])){
                src.erase(0, 1);
            }
            return src;
        }
        bool m_checkForSpacesAfter(const std::string& src)
        {  

            bool check = false;
            if(isspace(src[src.find_last_of(',') - 1])){
                check = true;
            }
            return check;
        }
}

/*int main(int argc, char** argv)
{   

    return 0;
}*/
#include "SpellChecker.h"


namespace sdds{

    SpellChecker::SpellChecker(const char* fileName)
    {
        /*a constructor that receives as a parameter the name of the file that contains the 
        misspelled words. If the file is missing, this constructor should generate an exception 
        of type const char*, with the message Bad file name!

        this constructor should load the content of the file. 
        Each line from the file is in the format BAD_WORD GOOD_WORD; the two fields can be 
        separated by any number of spaces.*/
        std::string theWords = "";
       
        std::ifstream fileObj(fileName);
        size_t countLines = 0;
        if(!fileObj){
            const char* errMessage = "Bad file name!";
            throw errMessage;
        }
        do
        {
            std::getline(fileObj, theWords);
            m_badWords[countLines] = theWords.substr(0, theWords.find_first_of(' '));
            theWords.erase(0, theWords.find_last_of(' ') + 1);
            m_goodWords[countLines] = theWords.substr(0, theWords.length());
            countLines++;

        }while (fileObj.good());

        fileObj.clear();
		fileObj.seekg(std::ios::beg);
        
    }

    void SpellChecker::operator()(std::string& text)
    {
        /*this operator should search in text if any of the misspelled words 
        appear and replace them with the correct version.*/

        for(size_t i = 0; i < 5; i++){
            if(text.find(m_badWords[i]) != std::string::npos){
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
            }
        }
    }

    

}

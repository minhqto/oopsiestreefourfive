#ifndef TEXT_H
#define TEXT_H

#include <string>

class Text{

    std::string* s;
    public:
    Text();
    Text(std::string);
    Text(Text&);
    Text& operator=(Text&);
    ~Text();

    size_t size() const;


};


#endif

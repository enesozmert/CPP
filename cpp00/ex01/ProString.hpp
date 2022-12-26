#ifndef PROSTRING_H
#define PROSTRING_H

#include <string>

class ProString
{
    private:
        std::string _text;
    public:
        ProString();
        ~ProString();
        std::string toUpper(std::string text);
        std::string toLower(std::string text);
        std::string cutLettersToTen(const std::string str);
};

#endif

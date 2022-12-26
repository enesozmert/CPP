#include "ProString.hpp"

ProString::ProString()
{
}

ProString::~ProString()
{
}

std::string ProString::toUpper(std::string text)
{
    int i;
    char *cstr;

    cstr = new char[text.length() + 1];
    i = -1;
    strcpy(cstr, text.c_str());
    while (cstr[++i])
    {
        if (cstr[i] >= 'a' && cstr[i] <= 'z')
            cstr[i] -= 32;
    }
    text = cstr;
    delete[] cstr;
    return (text);
}

std::string ProString::toLower(std::string text)
{
    int i;
    char *cstr;

    cstr = new char[text.length() + 1];
    i = -1;
    strcpy(cstr, text.c_str());
    while (cstr[++i])
    {
        if (cstr[i] >= 'A' && cstr[i] <= 'Z')
            cstr[i] += 32;
    }
    text = cstr;
    delete[] cstr;
    return (text);
}

std::string ProString::cutLettersToTen(const std::string str)
{
    std::string temp;

    if (str.length() > 10)
        temp = str.substr(0, 9) + ".";
    else
        temp = str;
    return (temp);
}
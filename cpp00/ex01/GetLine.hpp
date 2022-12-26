#ifndef GETLINE_H
#define GETLINE_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "ProString.hpp"

class GetLine
{
private:
    int error;
    std::string text;
public:
    GetLine();
    ~GetLine();
    GetLine Run(std::string type, std::string text);
    int getError();
    std::string getText();
};



#endif
#include "GetLine.hpp"

GetLine::GetLine()
{
}

GetLine::~GetLine()
{
}

GetLine GetLine::Run(std::string type, std::string text)
{
    GetLine getLine;
    std::cout << type << " : " << std::endl;
    if (!(std::getline(std::cin, text)))
        exit(1);
    if (std::cin.eof())
        exit(1);
    if (text.length() <= 0)
    {
        std::cout << "Error Length Zero" << std::endl;
        getLine.error = -1;
        return (getLine);
    }
    getLine.error = 0;
    getLine.text = text;
    return (getLine);
}

int GetLine::getError(void)
{
    return (this->error);
}

std::string GetLine::getText()
{
    return (this->text);
}
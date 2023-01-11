#pragma once

#include <iostream>

class CustomException : public std::exception
{
private:
public:
    class OutofBounds : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("ARRAYEXCEPTION: The Index is Out of Bounds");
        }
    };
};

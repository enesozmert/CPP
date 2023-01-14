#pragma once

#include <iostream>

class CustomException : public std::exception
{
    public:
        class NoPlaceLeft : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error : No Place Left");
                }
        };
        class NotEnoughElement : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error : Not Enough Element");
                }
        };
};

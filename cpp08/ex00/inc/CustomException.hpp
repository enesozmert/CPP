#pragma once

#include <iostream>

class CustomException : public std::exception
{
    public:
        class NotFound : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return ("Error : Element not found.");
            }
        };
};

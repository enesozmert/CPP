#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cstring>
#include <math.h>

class Convert
{
    public:
        Convert(const char *number);
        Convert(const Convert &scalarString);
        virtual ~Convert();

        Convert &operator=(const Convert &scalarString);
        operator int() const;
        operator char() const;
        operator float() const;
        operator double() const;

        class ImpossibleException : public std::exception
        {
        public:
            const char *what() const throw();
        };
        class NonDisplayableException : public std::exception
        {
        public:
            const char *what() const throw();
        };

    private:
        Convert();
        std::string number;
};
std::ostream &operator<<(std::ostream &ostream, const Convert &convert);

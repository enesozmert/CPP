#pragma once

#include <iostream>

class CustomException : public std::exception
{
    private:

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Exception : Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Exception : Grade is too low");
                }
        };
};

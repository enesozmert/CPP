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
        
        class ExecuteNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("form is not signed"); }
		};
		
		class FileOpeningFail : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("file cannot be opened"); }
		};
};

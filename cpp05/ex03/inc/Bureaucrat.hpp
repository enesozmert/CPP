#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>
# include "AForm.hpp"
# include "CustomException.hpp"

class AForm;
class CustomException;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        void checkGradeHighOrLow(int grade);
        const std::string getName(void) const;
        int getGrade() const;
        void upGrade();
        void downGrade();
        void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;
        Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);
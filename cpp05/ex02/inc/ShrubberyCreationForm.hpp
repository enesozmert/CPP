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
# include <fstream>
# include "CustomException.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm 
{
    private:
        const std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
        void execute(Bureaucrat const & executor) const;
        ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &shrubberyCreationForm);
        ~ShrubberyCreationForm();
};
std::ostream &operator<<(std::ostream &ostream, const ShrubberyCreationForm &shrubberyCreationForm);
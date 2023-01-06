#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

#include <string>
#include <iostream>
#include <iomanip>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class AForm;

class Intern
{
    private:
    public:
        Intern();
        Intern(const Intern &intern);
        Intern &operator=(const Intern &intern);
        AForm *makeForm(std::string formName, std::string target);
        ~Intern();
};
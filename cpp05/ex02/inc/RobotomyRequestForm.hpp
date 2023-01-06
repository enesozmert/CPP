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
# include "CustomException.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
        void execute(Bureaucrat const & executor) const;
        RobotomyRequestForm	&operator=(const RobotomyRequestForm &robotomyRequestForm);
        ~RobotomyRequestForm();
};
std::ostream &operator<<(std::ostream &ostream, const RobotomyRequestForm &robotomyRequestForm);

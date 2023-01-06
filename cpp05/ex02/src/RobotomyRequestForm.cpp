#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(__func__, 72, 45), _target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(__func__, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
{
    *this = robotomyRequestForm;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int	robotomized;

	this->AForm::executeCheck(executor);
	std::cout << "*rizZzzz BzzZz rZz* ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
    if (this == &robotomyRequestForm)
        return (*this);
    *const_cast<std::string *>(&this->_target) = robotomyRequestForm._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

#include "Intern.hpp"
typedef AForm *(*select_form)(const std::string);

Intern::Intern()
{
}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string _target)
{
    int i;
    std::string formNames[3];

    i = -1;
    formNames[0] = "presidential pardon";
    formNames[1] = "robotomy request";
    formNames[2] = "shrubbery creation";
    select_form p[3] = {&newShrubbery, &newRobotomy, &newPresidential};
    while (++i < 3)
    {
        if (formNames[i].compare(formName) == 0)
            return((*p[i])(_target));
    }
    if (i > 2 || i < 0)
        std::cout << "[ Undefined Form ]" << std::endl;
    return(NULL);
}

Intern &Intern::operator=(const Intern &intern)
{
    if (this == &intern)
        return (*this);
    return (*this);
}

Intern::~Intern()
{
}

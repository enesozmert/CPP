#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(__func__, 25, 5), _target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm(__func__, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
{
    *this = presidentialPardonForm;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->AForm::executeCheck(executor);
	std::cout << PURPLE << _target << END << " was forgiven by Zafor Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
    if (this == &presidentialPardonForm)
        return (*this);
    *const_cast<std::string*>(&this->_target) = presidentialPardonForm._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
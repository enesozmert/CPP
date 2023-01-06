#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(__func__, 145, 137), _target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(__func__, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm)
{
    *this = shrubberyCreationForm;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream file;

    this->AForm::executeCheck(executor);
    file.open((_target + "_shrubbery").c_str());
    if (file.good() == false)
        throw CustomException::FileOpeningFail();
    file << "              v .   ._, |_  .," << std::endl;
    file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\\\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
    file << "       \'7-,--.\'._||  / / ," << std::endl;
    file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /   " << _target << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
    file << "----------------/ ,  . \\--------._" << std::endl;
    file.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
    if (this == &shrubberyCreationForm)
        return (*this);
    *const_cast<std::string *>(&this->_target) = shrubberyCreationForm._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
    this->_grade = 0;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    checkGradeHighOrLow(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
}

void Bureaucrat::checkGradeHighOrLow(int gradeSign)
{
    if (gradeSign < 1)
        CustomException::GradeTooLowException();
    else if (gradeSign > 150)
        CustomException::GradeTooHighException();
}


const std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::upGrade()
{
    checkGradeHighOrLow(this->_grade);
    _grade--;
}

void Bureaucrat::downGrade()
{
    checkGradeHighOrLow(this->_grade);
    _grade++;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << YELLOW << _name << END << " signs " << GREEN << form.getName() << END << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW << _name << END << " cannot sign " << GREEN << form.getName() << END <<  " because " << BLUE << e.what() << END << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << YELLOW << _name << END << " executes " << GREEN << form.getName() << END << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << YELLOW << _name << END << " cannot executes " << GREEN << form.getName() << END <<  " because " << BLUE << e.what() << END << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
        return (*this);
		_grade = bureaucrat._grade;
	return (*this);
}

std::ostream  &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (ostream);
}

Bureaucrat::~Bureaucrat()
{

}
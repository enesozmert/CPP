#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(150)
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

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::upGrade()
{
    checkGradeHighOrLow(this->_grade);
    this->_grade--;
}

void Bureaucrat::downGrade()
{
    checkGradeHighOrLow(this->_grade);
    this->_grade++;
}

void Bureaucrat::GradeTooHighException()
{
    std::string result = "Bureaucrat ";

    result.append(__func__);
    throw std::invalid_argument(result);
}

void Bureaucrat::GradeTooLowException()
{
    std::string result = "Bureaucrat ";

    result.append(__func__);
    throw std::invalid_argument(result);
}

void Bureaucrat::checkGradeHighOrLow(int grade)
{
    if (grade < 1)
        GradeTooLowException();
    else if (grade > 150)
        GradeTooHighException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this == &bureaucrat)
        return (*this);
    *const_cast<std::string*>(&this->_name) = bureaucrat._name;
    this->_grade = bureaucrat._grade;
    checkGradeHighOrLow(bureaucrat.getGrade());
    return (*this);
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
    ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (ostream);
}

Bureaucrat::~Bureaucrat()
{

}
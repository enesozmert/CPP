#include "Form.hpp"

Form::Form() : _name("none"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
}

Form::Form(const std::string name, int gradeSign, int gradeExec) :
	_name(name),_isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    checkGradeSignHighOrLow(gradeSign);
    checkGradeExecHighOrLow(gradeExec);
}

Form::Form(const Form &form)
{
    *this = form;
}

void Form::checkGradeSignHighOrLow(int gradeSign)
{
    if (gradeSign < 1)
        CustomException::GradeTooLowException();
    else if (gradeSign > 150)
        CustomException::GradeTooHighException();
}

void Form::checkGradeExecHighOrLow(int gradeExec)
{
    if (gradeExec < 1)
        CustomException::GradeTooLowException();
    else if (gradeExec > 150)
        CustomException::GradeTooHighException();
}

const std::string Form::getName(void) const
{
	return (_name);
}

int		Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getSigned(void) const
{
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw CustomException::GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
    ostream << "[" << form.getName() << "]" << std::endl;
	ostream << "\t" << "signed : " << form.getSigned() << std::endl;
	ostream << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	ostream << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
    return (ostream);
}


Form &Form::operator=(const Form &form)
{
    if (this == &form)
        return (*this);
    _isSigned = form._isSigned;
    return (*this);
}

Form::~Form(){}

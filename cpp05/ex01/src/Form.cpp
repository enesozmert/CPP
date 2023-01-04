#include "Form.hpp"

Form::Form() : _name("none"), _gradeSign(150), _gradeExec(150), _isSigned(false)
{
}

Form::Form(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _isSigned(false)
{
    checkGradeExecHighOrLow(gradeExec);
    checkGradeSignHighOrLow(gradeSign);
}

Form::Form(const Form &form)
{
    *this = form;
}

void Form::GradeTooHighException()
{
    std::string result = "Bureaucrat ";

    result.append(__func__);
    throw std::invalid_argument(result);
}

void Form::GradeTooLowException()
{
    std::string result = "Bureaucrat ";

    result.append(__func__);
    throw std::invalid_argument(result);
}

void Form::checkGradeSignHighOrLow(int gradeSign)
{
    if (gradeSign < 1)
        GradeTooLowException();
    else if (gradeSign > 150)
        GradeTooHighException();
}

void Form::checkGradeExecHighOrLow(int gradeExec)
{
    if (gradeExec < 1)
        GradeTooLowException();
    else if (gradeExec > 150)
        GradeTooHighException();
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		GradeTooLowException();
	_isSigned = true;
}

const std::string   Form::getName(void) const
{
	return (_name);
}

int		Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
    ostream << "[" << form.getName() << "]" << std::endl;
	ostream << "\t" << "signed : " << form.getSigned() << std::endl;
	ostream << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	ostream << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
    return (ostream);
}


Form &operator=(const Form &form)
{
    if (this == *form)
        return (*this);
    _signed = form._signed;
    return (*this);
}

Form::~Form()
{
}

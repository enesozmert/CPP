#include "AForm.hpp"

AForm::AForm() : _name("none"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    checkGradeSignHighOrLow(gradeSign);
    checkGradeExecHighOrLow(gradeExec);
}

AForm::AForm(const AForm &form)
{
    *this = form;
}

void AForm::checkGradeSignHighOrLow(int gradeSign)
{
    if (gradeSign < 1)
        CustomException::GradeTooLowException();
    else if (gradeSign > 150)
        CustomException::GradeTooHighException();
}

void AForm::checkGradeExecHighOrLow(int gradeExec)
{
    if (gradeExec < 1)
        CustomException::GradeTooLowException();
    else if (gradeExec > 150)
        CustomException::GradeTooHighException();
}


const std::string AForm::getName(void) const
{
    return (_name);
}

int AForm::getGradeSign(void) const
{
    return (_gradeSign);
}

int AForm::getGradeExec(void) const
{
    return (_gradeExec);
}

bool AForm::getSigned(void) const
{
    return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
		throw CustomException::GradeTooLowException();
	_isSigned = true;
}

void AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw CustomException::ExecuteNotSigned();
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw CustomException::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &form)
{
    if (this == &form)
        return (*this);
    _isSigned = form._isSigned;
    return (*this);
}

std::ostream &operator<<(std::ostream &ostream, const AForm &form)
{
    ostream << "[" << form.getName() << "]" << std::endl;
	ostream << "\t" << "signed : " << form.getSigned() << std::endl;
	ostream << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	ostream << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return (ostream);
}

AForm::~AForm()
{
}

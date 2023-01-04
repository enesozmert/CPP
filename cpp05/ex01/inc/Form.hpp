#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        int _gradeSign;
        int _gradeExec;
    public:
        Form();
        Form(const std::string name, int gradeSign, int gradeExec);
        Form(const Form &form);
        void GradeTooLowException();
        void GradeTooHighException();
        void Form::checkGradeSignHighOrLow(int gradeSign); 
        void Form::checkGradeExecHighOrLow(int gradeExec);
        void beSigned(const Bureaucrat &bureaucrat);
        const std::string getName(void) const;
        int getSigned(void) const;
        int gradeSign(void) const;
        int gradeExec(void) const;
        Form &operator=(const Form &form);
        ~Form();
};
std::ostream &operator<<(std::ostream &ostream, const Form &form);


#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"

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
        void checkGradeSignHighOrLow(int gradeSign); 
        void checkGradeExecHighOrLow(int gradeExec);
        const std::string getName(void) const;
        int	getGradeSign(void) const;
        int	getGradeExec(void) const;
        bool getSigned(void) const;
        int gradeSign(void) const;
        int gradeExec(void) const;
        void beSigned(const Bureaucrat &bureaucrat);
        Form &operator=(const Form &form);
        ~Form();
};
std::ostream &operator<<(std::ostream &ostream, const Form &form);


#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        std::string getName(void) const;
        int getGrade() const;
        void upGrade();
        void downGrade();
        void GradeTooHighException();
        void GradeTooLowException();
        void checkGradeHighOrLow(int grade);
        void Bureaucrat::signForm(Form &form) const;
        Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);
#pragma once


# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>
# include "CustomException.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;
class CustomException;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        int _gradeSign;
        int _gradeExec;

    public:
        AForm();
        AForm(const AForm &Form);
		AForm(const std::string name, int gradeSign, int gradeExec);
        void checkGradeSignHighOrLow(int gradeSign);
        void checkGradeExecHighOrLow(int gradeExec);
        const std::string getName(void) const;
        int	getGradeSign(void) const;
        int	getGradeExec(void) const;
        bool getSigned(void) const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
		void executeCheck(const Bureaucrat &bureaucrat) const;
		AForm &operator=(const AForm &form);
        virtual ~AForm();
};
std::ostream &operator<<(std::ostream &ostream, const AForm &form);
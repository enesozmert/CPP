#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include "ALiteral.hpp"

class IntLiteral: public ALiteral
{
    private:
        int _num;
    public:
        IntLiteral();
        IntLiteral(const IntLiteral &intLiteral);
        const int getNum() const;
        void setNum(int num);
        bool getResult() const;
        void run(ALiteral const &literal);
        IntLiteral &operator=(const IntLiteral &intLiteral);
        ~IntLiteral();
};
std::ostream &operator<<(std::ostream &ostream, const IntLiteral &intLiteral);

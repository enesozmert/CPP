#pragma once

# include "ALiteral.hpp"

class IntLiteral: public ALiteral
{
    private:
        
    public:
        IntLiteral();
        IntLiteral(const char * value);
        IntLiteral(const IntLiteral &intLiteral);
        int getIntValue() const;
        void setIntValue(int intValue);
        bool getOutOfRange() const;
        void convert();
        void checkOutOfRange();
        bool checkType();
        void print(std::ostream &o) const;
        IntLiteral &operator=(const IntLiteral &intLiteral);
        ~IntLiteral();
};
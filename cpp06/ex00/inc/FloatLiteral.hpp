#pragma once

# include "ALiteral.hpp"

class FloatLiteral: public ALiteral
{
    private:
        int _floatValue;
    public:
        FloatLiteral();
        FloatLiteral(const char * value);
        FloatLiteral(const FloatLiteral &intLiteral);
        int getFloatValue() const;
        void setFloatValue(int floatValue);
        bool getOutOfRange() const;
        void convert();
        void checkOutOfRange();
        bool checkType();
        void print(std::ostream &o) const;
        FloatLiteral &operator=(const FloatLiteral &intLiteral);
        ~FloatLiteral();
};
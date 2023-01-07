#pragma once

# include "ALiteral.hpp"

class DoubleLiteral: public ALiteral
{
    private:
        int _doubleValue;
    public:
        DoubleLiteral();
        DoubleLiteral(const char * value);
        DoubleLiteral(const DoubleLiteral &doubleLiteral);
        int getDoubleValue() const;
        void setDoubleValue(int doubleValue);
        bool getOutOfRange() const;
        void convert();
        void checkOutOfRange();
        bool checkType();
        void print(std::ostream &o) const;
        DoubleLiteral &operator=(const DoubleLiteral &doubleLiteral);
        ~DoubleLiteral();
};
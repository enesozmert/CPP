#pragma once

# include "ALiteral.hpp"

class CharLiteral: public ALiteral
{
    private:
    public:
        CharLiteral();
        CharLiteral(const char * value);
        CharLiteral(const CharLiteral &charLiteral);
        int getCharValue() const;
        void setCharValue(int intValue);
        bool getOutOfRange() const;
        void checkOutOfRange();
        bool checkType();
        void convert();
        void print(std::ostream &o) const;
        CharLiteral &operator=(const CharLiteral &charLiteral);
        ~CharLiteral();
};

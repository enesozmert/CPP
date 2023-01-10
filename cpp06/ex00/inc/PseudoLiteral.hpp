#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include "ALiteral.hpp"

class PseudoLiteral: public ALiteral
{
    private:
        std::string	_limits[4];
    public:
        PseudoLiteral();
        PseudoLiteral(const char * value);
        PseudoLiteral(const PseudoLiteral &pseudoLiteral);
        bool getOutOfRange() const;
        bool checkType();
        void checkOutOfRange();
        void convert();
        void print(std::ostream &o) const;
        PseudoLiteral &operator=(const PseudoLiteral &pseudoLiteral);
        ~PseudoLiteral();
};

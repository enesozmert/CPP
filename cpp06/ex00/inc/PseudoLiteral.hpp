#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include "ALiteral.hpp"

class PseudoLiteral: public ALiteral
{
    private:
        std::string	_limits[4];
        std::string	_limit;
    public:
        PseudoLiteral();
        PseudoLiteral(const PseudoLiteral &pseudoLiteral);
        bool getOutOfRange() const;
        bool checkType();
        void checkOutOfRange();
        void convert();
        PseudoLiteral &operator=(const PseudoLiteral &pseudoLiteral);
        ~PseudoLiteral();
};
std::ostream &operator<<(std::ostream &ostream, const PseudoLiteral &pseudoLiteral);

#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# include "IntLiteral.hpp"
# include "FloatLiteral.hpp"
# include "DoubleLiteral.hpp"
# include "CharLiteral.hpp"
# include "PseudoLiteral.hpp"

class Convert
{
    private:
        const char * _value;
        void selectType();
        bool convertToInt();
        bool convertToFloat();
        bool convertToDecimal();
        bool convertToChar();
    public:
        Convert();
        Convert(const char *value);
        Convert(const Convert &convert);
        Convert &operator=(const Convert &convert);
        const char * getValue();
        ~Convert();
};
std::ostream &operator<<(std::ostream &ostream, const Convert &convert);


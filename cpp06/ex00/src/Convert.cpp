#include "Convert.hpp"

typedef bool (Convert::*select_type)();

Convert::Convert() : _value("")
{
}

Convert::Convert(const char *value) : _value(value)
{
}

Convert::Convert(const Convert &convert)
{
    *this = convert;
}

bool Convert::convertToInt()
{
    IntLiteral intLiteral(_value);

    intLiteral.convert();
    return (intLiteral._isType);
}

bool Convert::convertToFloat()
{
    FloatLiteral floatLiteral(_value);

    floatLiteral.convert();
    return (floatLiteral._isType);
}

bool Convert::convertToDecimal()
{
    DoubleLiteral doubleLiteral(_value);

    doubleLiteral.convert();
    return (doubleLiteral._isType);
}

bool Convert::convertToChar()
{
    CharLiteral charLiteral(_value);

    charLiteral.convert();
    return (charLiteral._isType);
}

void Convert::selectType()
{
    int i;
    int result;

    select_type p[4] = {&Convert::convertToInt, &Convert::convertToFloat, &Convert::convertToDecimal, &Convert::convertToChar};
    while (++i < 4)
    {
        result = (this->*p[i])();
    }
}

const char * Convert::getValue()
{
    return (_value);
}

Convert &Convert::operator=(const Convert &convert)
{
    if (this == &convert)
        return (*this);
    _value = convert._value;
    return (*this);
}

std::ostream &operator<<(std::ostream &ostream, const Convert &convert)
{
    const IntLiteral intLiteral(res);
    intLiteral.print(ostream);
    return (ostream);
}

Convert::~Convert()
{
}
#include "Convert.hpp"

typedef bool (Convert::*select_type)();

Convert::Convert() : _value("")
{
}

Convert::Convert(const char *value) : _value(value)
{
    // IntLiteral intLiteral(_value);

    // intLiteral.convert();
    // std::cout << intLiteral.getIntValue() << std::endl;
    selectType();
}

Convert::Convert(const Convert &convert)
{
    *this = convert;
    selectType();
}

bool Convert::convertToInt()
{
    IntLiteral intLiteral(_value);

    intLiteral.convert();
    intLi = intLiteral;
    return (intLiteral._isType);
}

bool Convert::convertToFloat()
{
    FloatLiteral floatLiteral(_value);

    floatLiteral.convert();
    floatLi = floatLiteral;
    return (floatLiteral._isType);
}

bool Convert::convertToDouble()
{
    DoubleLiteral doubleLiteral(_value);

    doubleLiteral.convert();
    doubleLi = doubleLiteral;
    return (doubleLiteral._isType);
}

bool Convert::convertToChar()
{
    CharLiteral charLiteral(_value);

    charLiteral.convert();
    charLi = charLiteral;
    return (charLiteral._isType);
}

void Convert::selectType()
{
    int i;
    int result;

    i = -1;
    select_type p[4] = {&Convert::convertToInt,&Convert::convertToFloat,&Convert::convertToDouble,&Convert::convertToChar};
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

std::ostream &operator<<(std::ostream &ostream, Convert &convert)
{
    convert.intLi.print(ostream);
    convert.floatLi.print(ostream);
    convert.doubleLi.print(ostream);
    convert.charLi.print(ostream);
    return (ostream);
}

Convert::~Convert()
{
}
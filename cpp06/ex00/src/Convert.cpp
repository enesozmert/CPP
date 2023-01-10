#include "Convert.hpp"

typedef void (Convert::*convert_type)();
typedef void (ALiteral::*get_type)();

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

void Convert::convertToInt()
{
    IntLiteral intLiteral(_value);

    intLiteral.convert();
    intLi = intLiteral;
}

void Convert::convertToFloat()
{
    FloatLiteral floatLiteral(_value);

    floatLiteral.convert();
    floatLi = floatLiteral;
}

void Convert::convertToDouble()
{
    DoubleLiteral doubleLiteral(_value);

    doubleLiteral.convert();
    doubleLi = doubleLiteral;
}

void Convert::convertToChar()
{
    CharLiteral charLiteral(_value);

    charLiteral.convert();
    charLi = charLiteral;
}

void Convert::selectType()
{
    int i;

    i = -1;
    convert_type select_types[4] = {&Convert::convertToInt,&Convert::convertToFloat,&Convert::convertToDouble,&Convert::convertToChar};
    get_type get_types[4] = {&IntLiteral::checkType,&IntLiteral::checkType,&IntLiteral::checkType,&IntLiteral::checkType};
    while (++i < 4)
    {
        (this->*select_types[i])();
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
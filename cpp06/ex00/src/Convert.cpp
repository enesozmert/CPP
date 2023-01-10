#include "Convert.hpp"

typedef void (Convert::*createLiteral)();

Convert::Convert() : _value("")
{
}

Convert::Convert(const char *value) : _value(value)
{
    selectType();
}

Convert::Convert(const Convert &convert)
{
    *this = convert;
    selectType();
}

void Convert::convertAll(ALiteral *literal)
{
    if (literal->checkType())
    {
        std::cout << "Error: invalid type" << std::endl;
        exit(0) ;
    }
    else
    {
        literal->checkOutOfRange();
        literal->convert();
    }
    if (literal->_isOutOfRange)
    {
        std::cout << "Error: values out of range" << std::endl;
        exit(0) ;
    }
    if (literal->_isStringError)
    {
        std::cout << "Error: string format error" << std::endl;
        exit(0) ;
    }
}

void Convert::convertToInt()
{
    IntLiteral intLiteral(_value);

    intLi = intLiteral;
}

void Convert::convertToFloat()
{
    FloatLiteral floatLiteral(_value);

    floatLi = floatLiteral;
}

void Convert::convertToDouble()
{
    DoubleLiteral doubleLiteral(_value);

    doubleLi = doubleLiteral;
}

void Convert::convertToChar()
{
    CharLiteral charLiteral(_value);

    charLi = charLiteral;
}

void Convert::convertToPseudo()
{
    PseudoLiteral pseudoLiteral(_value);

    pseudoLi = pseudoLiteral;
}

void Convert::selectType()
{
    int i;

    i = -1;
    createLiteral createLiterals[4] = {&Convert::convertToInt,&Convert::convertToFloat,&Convert::convertToDouble,&Convert::convertToChar};
    while (++i < 4)
    {
        (this->*createLiterals[i])();
    }
    convertAll(&intLi);
    convertAll(&floatLi);
    convertAll(&doubleLi);
    convertAll(&charLi);
    convertAll(&pseudoLi);
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
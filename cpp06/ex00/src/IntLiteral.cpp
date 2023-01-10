#include "IntLiteral.hpp"

IntLiteral::IntLiteral() : ALiteral("")
{
}

IntLiteral::IntLiteral(const char * value) : ALiteral(value)
{
}

IntLiteral::IntLiteral(const IntLiteral &intLiteral)
{
    *this = intLiteral;
}

int IntLiteral::getIntValue() const
{
    return (_intValue);
}

void IntLiteral::setIntValue(int intValue)
{
    _intValue = intValue;
}

bool IntLiteral::getOutOfRange() const
{
    return (_isOutOfRange);
}

void IntLiteral::checkOutOfRange()
{
    if ((strlen(_value) == 10 && strcmp(_value, "2147483647") > 0) || (_value[0] == '-' && strlen(_value) == 11 && strcmp(_value + 1, "2147483648") > 0) || (_value[0] == '+' && strlen(_value) == 11 && strcmp(_value + 1, "2147483647") > 0))
        _isOutOfRange = true;
    else
        _isOutOfRange = false;
}

bool IntLiteral::checkType()
{
    int i;

    i = -1;
    _isType = true;
    while (_value[++i] && _value[i] >= '0' && _value[i] <= '9')
    {
        _isType = false;
    }
    return (_isType);
}

void IntLiteral::convert()
{
    if (_isOutOfRange)
        return;
    _intValue = atoi(_value);
    if (isascii(_value[0]) && strlen(_value) == 1 && !isdigit(_value[0]))
    {
        _intValue = static_cast<char>(_value[0]);
        _charValue = static_cast<char>(_intValue);
    }
    _isConvert = true;
}

void	IntLiteral::print(std::ostream &o) const
{
	o << "int: ";
	if (!_isConvert)
	{
		o << "impossible" << std::endl;
		return ;
	}
	o << _intValue << std::endl;
}

IntLiteral &IntLiteral::operator=(const IntLiteral &intLiteral)
{
    if (this == &intLiteral)
        return (*this);
    _intValue = intLiteral._intValue;
    _floatValue = intLiteral._floatValue;
    _doubleValue = intLiteral._doubleValue;
    _charValue = intLiteral._charValue;
    _isConvert = intLiteral._isConvert;
    _isOutOfRange = intLiteral._isOutOfRange;
    _isStringError = intLiteral._isStringError;
    _isType = intLiteral._isType;
    _limit = intLiteral._limit;
    _isLimit = intLiteral._isLimit;
    _value = intLiteral._value;
    return (*this);
}

IntLiteral::~IntLiteral()
{
}
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

    i = 0;
    _isType = false;
    while (_value[i] && _value[i] >= '0' && _value[i] <= '9')
    {
        _isType = true;
        i++;
    }
    if (isalpha(_value[0]) && strlen(_value) == 1)
        _isType = true;
    return (_isType);
}

void IntLiteral::convert()
{
    if (_isOutOfRange)
        return;
    if (isalpha(_value[0]) && strlen(_value) == 1)
        _intValue = static_cast<int>(_value[0]);
    else if (_isType)
        _intValue = atoi(_value);
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
    return (*this);
}

IntLiteral::~IntLiteral()
{
}
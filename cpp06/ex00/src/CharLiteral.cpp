#include "CharLiteral.hpp"

#include "CharLiteral.hpp"

CharLiteral::CharLiteral() : ALiteral("")
{
}

CharLiteral::CharLiteral(const char * value) : ALiteral(value)
{
}

CharLiteral::CharLiteral(const CharLiteral &charLiteral)
{
    *this = charLiteral;
}

int CharLiteral::getCharValue() const
{
    return (_charValue);
}

void CharLiteral::setCharValue(int charValue)
{
    _charValue = charValue;
}

bool CharLiteral::getOutOfRange() const
{
    return (_isOutOfRange);
}

void CharLiteral::checkOutOfRange()
{
    if (_value[0] < -128 || _value[0] > 127)
        _isOutOfRange = true;
    else
        _isOutOfRange = false;
}

bool CharLiteral::checkType()
{
    int i;

    i = 0;
    _isType = false;
    if (isascii(_value[0]) && strlen(_value) == 1)
        _isType = true;
    return (false);
}

void CharLiteral::convert()
{
    char	*end = NULL;
    if (_isOutOfRange)
        return;
    _doubleValue =  std::strtod(_value, &end);
    if (isascii(_value[0]) && strlen(_value) == 1)
	    _charValue = _value[0];
    else
        _charValue = static_cast<double>(_doubleValue);
    _isConvert = true;
}

void	CharLiteral::print(std::ostream &o) const
{
	o << "char: ";
	if (!_isConvert)
	{
		o << "impossible" << std::endl;
		return ;
	}
	if (_charValue > 31 && _charValue < 127)
		o << "'" << _charValue << "'" << std::endl;
	else
		o << "Non displayable" << std::endl;
}

CharLiteral &CharLiteral::operator=(const CharLiteral &charLiteral)
{
    if (this == &charLiteral)
        return (*this);
    _intValue = charLiteral._intValue;
    _floatValue = charLiteral._floatValue;
    _doubleValue = charLiteral._doubleValue;
    _charValue = charLiteral._charValue;
    _isConvert = charLiteral._isConvert;
    _isOutOfRange = charLiteral._isOutOfRange;
    _isStringError = charLiteral._isStringError;
    _isType = charLiteral._isType;
    _limit = charLiteral._limit;
    _isLimit = charLiteral._isLimit;
    _value = charLiteral._value;
    return (*this);
}

CharLiteral::~CharLiteral()
{
}
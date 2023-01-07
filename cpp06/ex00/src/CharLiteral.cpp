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
    return (_isType);
}

void CharLiteral::convert()
{
    if (_isOutOfRange)
        return;
    if (isalpha(_isType))
        _charValue = static_cast<char>(_value[0]);
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
		o << "non displayable" << std::endl;
}

CharLiteral &CharLiteral::operator=(const CharLiteral &charLiteral)
{
    if (this == &charLiteral)
        return (*this);
    _charValue = charLiteral._charValue;
    return (*this);
}

CharLiteral::~CharLiteral()
{
}
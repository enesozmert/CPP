#include "DoubleLiteral.hpp"

DoubleLiteral::DoubleLiteral() : ALiteral("")
{
}

DoubleLiteral::DoubleLiteral(const char * value) : ALiteral(value)
{
}

DoubleLiteral::DoubleLiteral(const DoubleLiteral &doubleLiteral)
{
    *this = doubleLiteral;
}

int DoubleLiteral::getDoubleValue() const
{
    return (_doubleValue);
}

void DoubleLiteral::setDoubleValue(int doubleValue)
{
    _doubleValue = doubleValue;
}

bool DoubleLiteral::getOutOfRange() const
{
    return (_isOutOfRange);
}

void DoubleLiteral::checkOutOfRange()
{
    double doubleValue;

	char	*end;

	doubleValue = std::strtold(_value, &end);
    if (doubleValue < -std::numeric_limits<double>::max() || doubleValue > std::numeric_limits<double>::max())
        _isOutOfRange = true;
    else
        _isOutOfRange = false;
}

bool DoubleLiteral::checkType()
{
    int i;

    i = 0;
    _isType = false;
    while (_value[i] && _value[i] >= '0' && (_value[i] <= '9' || _value[i] == '.'))
    {
        if (_value[0] == '.' || _value[strlen(_value) - 1] == '.')
            _isType = false;
        _isType = true;
        i++;
    }
    return (false);
}

void DoubleLiteral::convert()
{
    char	*end = NULL;
    if (_isOutOfRange)
        return;
    _doubleValue =  std::strtod(_value, &end);
	if (errno == ERANGE)
	{
		_isOutOfRange = true;
		return ;
	}
    if (isascii(_value[0]) && strlen(_value) == 1)
    {
        _doubleValue = static_cast<char>(_value[0]);
        _charValue = static_cast<char>(_intValue);
    }
    _isConvert = true;
}

void	DoubleLiteral::print(std::ostream &o) const
{
	o << "double: ";
	if (!_isConvert)
	{
		o << "impossible" << std::endl;
		return ;
	}
	if (_isLimit)
		o << _limit << std::endl;
	else
	{
		o.precision(1);
		o << std::fixed << _doubleValue << std::endl;
	}
}

DoubleLiteral &DoubleLiteral::operator=(const DoubleLiteral &doubleLiteral)
{
    if (this == &doubleLiteral)
        return (*this);
    _intValue = doubleLiteral._intValue;
    _floatValue = doubleLiteral._floatValue;
    _doubleValue = doubleLiteral._doubleValue;
    _charValue = doubleLiteral._charValue;
    _isConvert = doubleLiteral._isConvert;
    _isOutOfRange = doubleLiteral._isOutOfRange;
    _isStringError = doubleLiteral._isStringError;
    _isType = doubleLiteral._isType;
    _limit = doubleLiteral._limit;
    _isLimit = doubleLiteral._isLimit;
    _value = doubleLiteral._value;
    return (*this);
}

DoubleLiteral::~DoubleLiteral()
{
}
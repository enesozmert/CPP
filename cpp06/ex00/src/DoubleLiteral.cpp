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
    if (*_value != '\0' || errno != 0) {std::abort(); }
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
    while (_value[i] && (_value[i] >= '0' && _value[i] <= '9') || _value[i] == '.')
    {
        if (_value[0] == '.' || _value[strlen(_value) - 1] == '.')
            _isType = false;
        _isType = true;
        i++;
    }
    return (_isType);
}

void DoubleLiteral::convert()
{
    int intValue;

    if (_isOutOfRange)
        return;
    if (isalpha(_value[0]) && strlen(_value) == 1)
    {
        intValue = atoi(_value);
        _doubleValue = static_cast<int>(intValue);
    }
    else if (_isType)
        _doubleValue = static_cast<double>(_doubleValue);
}

DoubleLiteral &DoubleLiteral::operator=(const DoubleLiteral &doubleLiteral)
{
    if (this == &doubleLiteral)
        return (*this);
    _doubleValue = doubleLiteral._doubleValue;
    return (*this);
}

DoubleLiteral::~DoubleLiteral()
{
}
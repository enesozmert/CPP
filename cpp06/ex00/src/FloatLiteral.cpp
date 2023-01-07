#include "FloatLiteral.hpp"

FloatLiteral::FloatLiteral() : ALiteral("")
{
}

FloatLiteral::FloatLiteral(const char * value) : ALiteral(value)
{
}

FloatLiteral::FloatLiteral(const FloatLiteral &floatLiteral)
{
    *this = floatLiteral;
}

int FloatLiteral::getFloatValue() const
{
    return (_floatValue);
}

void FloatLiteral::setFloatValue(int floatValue)
{
    _floatValue = floatValue;
}

bool FloatLiteral::getOutOfRange() const
{
    return (_isOutOfRange);
}

void FloatLiteral::checkOutOfRange()
{
    double doubleValue;

	char	*end;

	doubleValue = std::strtod(_value, &end);
    if (*_value != '\0' || errno != 0) {std::abort(); }
    if (doubleValue < -std::numeric_limits<float>::max() || doubleValue > std::numeric_limits<float>::max())
        _isOutOfRange = true;
    else
        _isOutOfRange = false;
}

bool FloatLiteral::checkType()
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
    if (_value[i] == 'f')
        _isType = true;
    else
        _isType = false;
    return (_isType);
}

void FloatLiteral::convert()
{
    int intValue;

    if (_isOutOfRange)
        return;
    if (isalpha(_value[0]) && strlen(_value) == 1)
    {
        intValue = atoi(_value);
        _floatValue = static_cast<int>(intValue);
    }
    else if (_isType)
        _floatValue = static_cast<float>(_floatValue);
}

FloatLiteral &FloatLiteral::operator=(const FloatLiteral &floatLiteral)
{
    if (this == &floatLiteral)
        return (*this);
    _floatValue = floatLiteral._floatValue;
    return (*this);
}

FloatLiteral::~FloatLiteral()
{
}
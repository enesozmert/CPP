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
    while (_value[i] && ((_value[i] >= '0' && _value[i] <= '9') || _value[i] == '.'))
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

void	FloatLiteral::print(std::ostream &o) const
{
	o << "float: ";
	if (!_isConvert)
	{
		o << "impossible" << std::endl;
		return ;
	}
	// if (_isLimit)
	// 	o << "f" << std::endl;
	// else
	// {
		o.precision(1);
		o << std::fixed << _floatValue << "f" << std::endl;
	// }
}

void FloatLiteral::convert()
{
    char	*end = NULL;

    if (_isOutOfRange)
        return;
    _floatValue =  std::strtof(_value, &end);
    _doubleValue = static_cast<double>(_floatValue);
    _intValue = static_cast<int>(_floatValue);
    if (isalpha(_value[0]) && strlen(_value) == 1)
    {
        _floatValue = static_cast<char>(_value[0]);
        _charValue = static_cast<char>(_intValue);
    }
    _isConvert = true;
}

FloatLiteral &FloatLiteral::operator=(const FloatLiteral &floatLiteral)
{
    if (this == &floatLiteral)
        return (*this);
    _intValue = floatLiteral._intValue;
    _floatValue = floatLiteral._floatValue;
    _doubleValue = floatLiteral._doubleValue;
    _charValue = floatLiteral._charValue;
    _isConvert = floatLiteral._isConvert;
    _isLimit = floatLiteral._isLimit;
    _isOutOfRange = floatLiteral._isOutOfRange;
    _isType = floatLiteral._isType;
    _value = floatLiteral._value;
    return (*this);
}

FloatLiteral::~FloatLiteral()
{
}
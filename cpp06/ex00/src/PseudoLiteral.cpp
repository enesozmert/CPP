#include "PseudoLiteral.hpp"

PseudoLiteral::PseudoLiteral()
{
}

PseudoLiteral::PseudoLiteral(const PseudoLiteral &pseudoLiteral)
{
    *this = pseudoLiteral;
}

bool PseudoLiteral::getOutOfRange() const
{
    return (_isOutOfRange);
}

void PseudoLiteral::checkOutOfRange()
{
    _limits[0]="inf";
    _limits[1]="+inf";
    _limits[2]="-inf";
    _limits[3]="nan";
	for (int i = 0; i < 4; i++)
	{
		if (_value == _limits[i] || _value == (_limits[i] + "f"))
		{
			_limit = _limits[i];
			if (i == 1)
				_limit = _limits[0];
			_isLimit = true;
		}
	}
	_isLimit = false;
}

void PseudoLiteral::convert()
{
    return;
}

bool PseudoLiteral::checkType()
{
    return (false);
}

PseudoLiteral &PseudoLiteral::operator=(const PseudoLiteral &pseudoLiteral)
{
    if (this == &pseudoLiteral)
        return (*this);
    _limit = pseudoLiteral._limit;
    return (*this);
}

std::ostream &operator<<(std::ostream &ostream, const PseudoLiteral &pseudoLiteral)
{
    (void)pseudoLiteral;
    // if (_isOutOfRange)
	// 	ostream << "Error: values out of range" << std::endl;
    // ostream << "int: ";
    // if (!_isOutOfRange)
    // {
    //     ostream << "impossible" << std::endl;
    //     return;
    // }
    // ostream << _intValue << std::endl;
    return (ostream);
}

PseudoLiteral::~PseudoLiteral()
{
}
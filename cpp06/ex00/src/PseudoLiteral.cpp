#include "PseudoLiteral.hpp"

PseudoLiteral::PseudoLiteral(): ALiteral("")
{
}

PseudoLiteral::PseudoLiteral(const char * value) : ALiteral(value)
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
            _isLimit = true;
			_limit = _limits[i];
			if (i == 1)
				_limit = _limits[0];
			_isConvert = true;
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

void	PseudoLiteral::print(std::ostream &o) const
{
    (void)o;
}

PseudoLiteral &PseudoLiteral::operator=(const PseudoLiteral &pseudoLiteral)
{
    if (this == &pseudoLiteral)
        return (*this);
    _limit = pseudoLiteral._limit;
    return (*this);
}

PseudoLiteral::~PseudoLiteral()
{
}
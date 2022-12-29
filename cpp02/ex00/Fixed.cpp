#include "Fixed.hpp"

Fixed::Fixed(Fixed const &fixed)
{
    *this = fixed;
}

Fixed::Fixed() : _fixedPoint(0)
{
}

Fixed::Fixed(int number) : _fixedPoint(number)
{

}

Fixed& Fixed::operator = (Fixed const &fixed)
{
    if (this == &fixed)
        return (*this);
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

float Fixed::toFloat( void ) const
{

}

int Fixed::toInt( void ) const
{
    
}

Fixed::~Fixed()
{
    
}
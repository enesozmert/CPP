#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPoint = 0;
}

Fixed::Fixed(int number)
{
	std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = number << bitTransfer;
}

Fixed::Fixed( const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = (int)roundf(floatNumber * (1 << bitTransfer));
}

Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPoint / (1 << this->bitTransfer));
}
int Fixed::toInt( void ) const
{
    return ((int)(roundf((float)this->_fixedPoint / (1 << this->bitTransfer))));
}

int Fixed::getRawBits( void ) const
{
    return (_fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPoint = raw;
}

Fixed& Fixed::operator = (Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

std::ostream & operator << (std::ostream & os, Fixed const & f)
{
    os << f.toFloat();
	return (os);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
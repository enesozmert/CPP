#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(int number) : _fixedPoint(number)
{
    std::cout << "Default constructor overload called" << std::endl;
}

Fixed& Fixed::operator= (Fixed const &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBIts member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int raw )
{
	std::cout << "setRawBIts member function called" << std::endl;
	this->_fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
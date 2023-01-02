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

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = (int)roundf(floatNumber * (1 << bitTransfer));
}

Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return (*this);
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

bool Fixed::operator>(Fixed const &fixed) const
{
    return (this->_fixedPoint > fixed._fixedPoint);
}

bool Fixed::operator<(Fixed const &fixed) const
{
    return (this->_fixedPoint < fixed._fixedPoint);
}

bool Fixed::operator>=(Fixed const &fixed) const
{
    return (this->_fixedPoint >= fixed._fixedPoint);
}

bool Fixed::operator<=(Fixed const &fixed) const
{
    return (this->_fixedPoint <= fixed._fixedPoint);
}

bool Fixed::operator!=(Fixed const &fixed) const
{
    return (this->_fixedPoint != fixed._fixedPoint);
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    ++(this->_fixedPoint);
    return (*this);
}
Fixed &Fixed::operator--(void)
{
    --(this->_fixedPoint);
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    int i;
    Fixed temp;

    i = -1;
    temp = *this;
    if (n >= 0)
    {
        while (++i <= n)
            ++(*this);
    }
    else
    {
        while (++i <= (-n))
            --(*this);
    }
    return (temp);
}

Fixed Fixed::operator--(int n)
{
    int i;
    Fixed temp;

    i = -1;
    temp = *this;
    if (n >= 0)
    {
        while (++i <= n)
            --(*this);
    }
    else
    {
        while (++i <= (-n))
            ++(*this);
    }
    return (temp);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed)
{
    ostream << fixed.toFloat();
    return (ostream);
}

int Fixed::getRawBits(void) const
{
    return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPoint / (1 << this->bitTransfer));
}
int Fixed::toInt(void) const
{
    return ((int)(roundf((float)this->_fixedPoint / (1 << this->bitTransfer))));
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    std::cout << "Static min function called" << std::endl;
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    std::cout << "Static max function called" << std::endl;
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    std::cout << "Static const min overload called" << std::endl;
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    std::cout << "Static const max overload called" << std::endl;
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

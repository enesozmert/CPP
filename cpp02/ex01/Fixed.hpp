#pragma once

#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int _fixedPoint;
        static int const bitTransfer = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float floatNumber);
        Fixed(Fixed const &fixed);
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed & operator = (Fixed const & fixed);
        ~Fixed();
};
std::ostream & operator << (std::ostream & os, Fixed const & f);
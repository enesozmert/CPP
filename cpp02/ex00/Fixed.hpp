#pragma once

#include <iostream>

class Fixed
{
    private:
        int _fixedPoint;
        static int const bitTransfer = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(Fixed const &fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator = (Fixed const &fixed);
        ~Fixed();
};
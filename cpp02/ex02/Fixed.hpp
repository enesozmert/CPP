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
    Fixed &operator=(Fixed const &fixed);
    bool operator>(Fixed const &fixed) const;
    bool operator<(Fixed const &fixed) const;
    bool operator>=(Fixed const &fixed) const;
    bool operator<=(Fixed const &fixed) const;
    bool operator!=(Fixed const &fixed) const;

    Fixed operator+(Fixed const &fixed) const;
    Fixed operator-(Fixed const &fixed) const;
    Fixed operator*(Fixed const &fixed) const;
    Fixed operator/(Fixed const &fixed) const;

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &fixed1, Fixed &fixed2);
    static Fixed &max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
    static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
    ~Fixed();
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);
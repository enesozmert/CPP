#include <iostream>
#include "Fixed.hpp"
int main(void)
{
    Fixed a(1);

    a.setRawBits(5);
    Fixed b(a);
    b.setRawBits(4);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
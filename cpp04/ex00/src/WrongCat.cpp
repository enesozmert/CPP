#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal("Cat")
{
    *this = wrongCat;
}

void WrongCat::makeSound() const
{
    std::cout << "miyav" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &wrongCat)
{
    if (this == &wrongCat)
        return (*this);
    this->_type = wrongCat._type;
    return (*this);
}

WrongCat::~WrongCat()
{

}

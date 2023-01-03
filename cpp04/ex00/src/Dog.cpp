#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
    *this = dog;
}

void Dog::makeSound() const
{
    std::cout << "hav" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
    if (this == &dog)
        return (*this);
    this->_type = dog._type;
    return (*this);
}

Dog::~Dog()
{
}
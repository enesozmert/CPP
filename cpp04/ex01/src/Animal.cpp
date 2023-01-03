#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "*none*";
}

Animal::Animal(const std::string &type)
{
    this->_type = type;
}

Animal::Animal(const Animal &animal)
{
    this->_type = animal._type;
}

void Animal::makeSound() const
{
    std::cout << "*none*" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

Animal	&Animal::operator=(const Animal &animal)
{
    if (this == &animal)
        return (*this);
    this->_type = animal._type;
    return (*this);
}

Animal::~Animal()
{

}

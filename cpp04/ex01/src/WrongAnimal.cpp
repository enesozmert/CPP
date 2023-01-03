#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "*none*";
}

WrongAnimal::WrongAnimal(const std::string &type)
{
    this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    this->_type = wrongAnimal._type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*none*" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    if (this == &wrongAnimal)
        return (*this);
    this->_type = wrongAnimal._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{

}

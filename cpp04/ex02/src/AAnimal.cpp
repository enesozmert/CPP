#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->_type = "*none*";
}

AAnimal::AAnimal(const std::string &type)
{
    this->_type = type;
}

AAnimal::AAnimal(const AAnimal &animal)
{
    this->_type = animal._type;
}

void AAnimal::makeSound() const
{
    std::cout << "*none*" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}

AAnimal	&AAnimal::operator=(const AAnimal &animal)
{
    if (this == &animal)
        return (*this);
    this->_type = animal._type;
    return (*this);
}

AAnimal::~AAnimal()
{

}

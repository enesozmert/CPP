#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    _brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
    _brain = new Brain(*dog._brain);
    *this = dog;
}

void Dog::makeSound() const
{
    std::cout << "hav" << std::endl;
}

void Dog::printIdeas() const
{
    std::cout << "miyav" << std::endl;
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
    std::cout << std::endl << RED << "[Dog]" << END << " destructor called" << std::endl;
	delete _brain;
}
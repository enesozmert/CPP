#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal("Dog")
{
    this->_brain = new Brain();
    this->printIdeas();
}

Dog::Dog(const Dog &dog) : AAnimal("Dog"), _brain(new Brain(*(dog._brain)))
{
    *this = dog;
}

void Dog::makeSound() const
{
    std::cout << "hav" << std::endl;
}

void Dog::printIdeas() const
{
    this->_brain->printFirstIdeas();
	std::cout << " at " << &this->_brain << std::endl;
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
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    this->_brain = new Brain();
    this->printIdeas();
}

Cat::Cat(const Cat &cat) : AAnimal("Cat"), _brain(new Brain(*(cat._brain)))
{
    *this = cat;
}

void Cat::makeSound() const
{
    std::cout << "miyav" << std::endl;
}

void Cat::printIdeas() const
{
    this->_brain->printFirstIdeas();
	std::cout << " at " << &this->_brain << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return (*this);
    this->_type = cat._type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << std::endl << RED << "[Cat]" << END << " destructor called" << std::endl;
	delete _brain;
}

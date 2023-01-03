#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    _brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
    _brain = new Brain(*cat._brain);
    *this = cat;
}

void Cat::makeSound() const
{
    std::cout << "miyav" << std::endl;
}

void Cat::printIdeas() const
{
    std::cout << "miyav" << std::endl;
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

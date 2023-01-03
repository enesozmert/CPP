#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
    *this = cat;
}

void Cat::makeSound() const
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

}

#pragma once

# include <string>
# include <iostream>
# include <iomanip>


#include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain	*_brain;
    public:
        Cat();
        Cat(const Cat &cat);
        void makeSound() const;
        void printIdeas() const;
        Cat	&operator=(const Cat &cat);
        ~Cat();
};
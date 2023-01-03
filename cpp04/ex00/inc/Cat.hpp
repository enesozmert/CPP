#pragma once

#include "Animal.hpp"

# include <string>
# include <iostream>
# include <iomanip>

class Cat : public Animal
{
    private:

    public:
        Cat();
        Cat(const Cat &cat);
        void makeSound() const;
        void printIdeas() const;
        Cat	&operator=(const Cat &cat);
        ~Cat();
};
#pragma once

#include "Animal.hpp"

# include <string>
# include <iostream>
# include <iomanip>

class Dog : public Animal
{
    private:

    public:
        Dog();
        Dog(const Dog &dog);
        void makeSound() const;
        void printIdeas() const;
        Dog	&operator=(const Dog &dog);
        ~Dog();
};


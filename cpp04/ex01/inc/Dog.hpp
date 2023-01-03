#pragma once


# include <string>
# include <iostream>
# include <iomanip>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain	*_brain;
    public:
        Dog();
        Dog(const Dog &dog);
        void makeSound() const;
		void printIdeas() const;
        Dog	&operator=(const Dog &dog);
        ~Dog();
};


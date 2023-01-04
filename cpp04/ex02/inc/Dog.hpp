#pragma once


# include <string>
# include <iostream>
# include <iomanip>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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


#pragma once

# include <string>
# include <iostream>
# include <iomanip>


# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
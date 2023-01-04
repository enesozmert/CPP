#pragma once

#include "WrongAnimal.hpp"

# include <string>
# include <iostream>
# include <iomanip>

class WrongCat : public WrongAnimal
{
    private:

    public:
        WrongCat();
        WrongCat(const WrongCat &wrongCat);
        void makeSound() const;
        WrongCat	&operator=(const WrongCat &wrongCat);
        ~WrongCat();
};
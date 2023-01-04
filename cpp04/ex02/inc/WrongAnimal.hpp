#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class WrongAnimal
{
    protected:
        std::string	_type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &animal);
        virtual void makeSound() const;
		std::string getType(void) const;
        WrongAnimal	&operator=(const WrongAnimal &animal);
        virtual ~WrongAnimal();
};
#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class AAnimal
{
    protected:
        std::string	_type;
    public:
        AAnimal();
        AAnimal(const std::string &type);
		AAnimal(const AAnimal &animal);
        virtual void makeSound() const = 0;
		std::string getType(void) const;
        AAnimal	&operator=(const AAnimal &animal);
        virtual ~AAnimal();
};
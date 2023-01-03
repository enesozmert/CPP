#pragma once

# include <string>
# include <iostream>
# include <iomanip>

class Animal
{
    protected:
        std::string	_type;
    public:
        Animal();
        Animal(const std::string &type);
		Animal(const Animal &animal);
        virtual void makeSound() const;
		std::string getType(void) const;
        Animal	&operator=(const Animal &animal);
        virtual ~Animal();
};
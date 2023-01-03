#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
    this->_name = "default-frag";
    std::cout << "ScavTrap " << this->_name << " constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "ScavTrap " << this->_name << " name constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	*this = fragTrap;
    std::cout << "ScavTrap copied " << this->_name << " copy constructor called!" << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << BLUE << _embedName() << END << "High Fives Guys!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hitPoints = fragTrap._hitPoints;
		this->_energyPoints = fragTrap._energyPoints;
		this->_attackDamage = fragTrap._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << _embedName() << END << "Robot down!" << std::endl;
}
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : 
	ClapTrap(), ScavTrap(), FragTrap()
{
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :
	ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	*this = diamondTrap;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->_name = diamondTrap._name;
		this->_hitPoints = diamondTrap._hitPoints;
		this->_energyPoints = diamondTrap._energyPoints;
		this->_attackDamage = diamondTrap._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << " and my clapName " << ClapTrap::_name << "!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << _embedName() << END << "Bye bye!" << std::endl;
}
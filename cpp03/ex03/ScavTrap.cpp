#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	this->_name = "default-scav";
    std::cout << "ScavTrap " << this->_name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	*this = scavTrap;
	std::cout << "ScavTrap copied " << this->_name << " copy constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " name constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hitPoints = scavTrap._hitPoints;
		this->_energyPoints = scavTrap._energyPoints;
		this->_attackDamage = scavTrap._attackDamage;
	}
	return (*this);
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << BLUE << _embedName() << END << "Gate keeper mode activated!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->_checkEnergyPointLock(*this, __func__) && !this->_checkDeadLock(*this, __func__))
		return;
	this->_energyPoints--;
	std::cout << "ScavTrap " << ORANGE << _embedName() << END << "Take that " << target << "! (-" << _attackDamage << "HP)" << std::endl;
	_showStats();
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << RED << _embedName() << END << "I have many regrets!" << std::endl;
}
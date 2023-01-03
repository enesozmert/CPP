#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    this->_name = "default-clap";
    std::cout << "ClapTrap " << this->_name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    this->_name = clapTrap._name;
    this->_hitPoints = clapTrap._hitPoints;
    this->_attackDamage = clapTrap._attackDamage;
    this->_energyPoints = clapTrap._energyPoints;
    std::cout << "ClapTrap copied " << clapTrap._name << " copy constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap " << this->_name << " name constructor called." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->_checkEnergyPointLock(*this, __func__) || !this->_checkDeadLock(*this, __func__))
        return;
    this->_energyPoints--;
    std::cout << "ClapTrap " << ORANGE << _embedName() << END << " attacks " << YELLOW << target << END << " causing " << this->_attackDamage << " points of damage!" << std::endl;
    _showStats();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->_checkEnergyPointLock(*this, __func__) || !this->_checkDeadLock(*this, __func__))
        return;
    if (amount > _hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << ORANGE << _embedName() << END << " has no more HP left before taking " << amount << " point of damage" << std::endl;
    }
    else
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << ORANGE << _embedName() << END << " takes " << amount << " point of damage!" << std::endl;
        if (_hitPoints == 0)
			std::cout << "ClapTrap " << RED << "Oh no " << BLUE << _name << END << RED << " is dead..." << END << std::endl;
    }
    _showStats();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->_checkEnergyPointLock(*this, __func__) || !this->_checkDeadLock(*this, __func__))
        return;
    this->_energyPoints--;
    std::cout << "ClapTrap " << ORANGE << _embedName() << END << " repairs himself " << amount << " point of damage!" << std::endl;
    _showStats();
}

bool ClapTrap::_checkEnergyPointLock(ClapTrap &clapTrap, std::string action)
{
    if (clapTrap._energyPoints < 1)
    {
        _impossibleAction(action, GREEN, "he has no energy left");
        return (0);
    }
    return (1);
}

bool ClapTrap::_checkDeadLock(ClapTrap &clapTrap, std::string action)
{
    if (clapTrap._hitPoints < 1)
    {
        _impossibleAction(action, PURPLE, "he's dead");
        return (0);
    }
    return (1);
}

void ClapTrap::setAttackDamage(unsigned int damage)
{
    this->_attackDamage = damage;
}

unsigned int ClapTrap::getAttackDamage(void)
{
    return (this->_attackDamage);
}

void	ClapTrap::_impossibleAction(std::string action, std::string color, std::string reason) const
{
	std::cout << "ClapTrap " << ORANGE << _name << END << " can't " << color << action << END << " since " << reason << std::endl;
}

std::string	ClapTrap::_embedName(void) const
{
	return ("[" + _name + "] ");
}

void	ClapTrap::_showStats(void) const
{
	std::cout << GRAY << _hitPoints << "HP";
	std::cout << std::setw(15) << _energyPoints << "EP";
	std::cout << std::setw(15) << _attackDamage << "AD" << END << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this == &clapTrap)
        return (*this);
    this->_name = clapTrap._name;
    this->_hitPoints = clapTrap._hitPoints;
    this->_energyPoints = clapTrap._energyPoints;
    this->_attackDamage = clapTrap._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "END" << std::setw(11) << RED << _embedName() << END << "I'm too pretty to die! No, nononono NO!" << std::endl;
}

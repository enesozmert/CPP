#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
    this->_name = "default";
    std::cout << "ClapTrap " << this->_name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &clapTrap)
{
    this->_name = clapTrap._name;
    this->_hitPoint = clapTrap._hitPoint;
    this->_attackDamage = clapTrap._attackDamage;
    this->_energyPoint = clapTrap._energyPoint;
    std::cout << "ClapTrap copied " << clapTrap._name << " constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    std::cout << "ClapTrap " << this->_name << " copy constructor called." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->checkEnergyPointLock(*this))
        return;
    this->_energyPoint--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->checkEnergyPointLock(*this))
        return;
    if (amount > _hitPoint)
    {
        this->_hitPoint = 0;
        std::cout << "ClapTrap " << this->_name << " has no more HP left before taking " << amount << " point of damage" << std::endl;
    }
    else
    {
        this->_hitPoint -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " point of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->checkEnergyPointLock(*this))
        return;
    this->_energyPoint--;
    std::cout << "ClapTrap " << this->_name << " repairs himself " << amount << " point of damage!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this == &clapTrap)
        return (*this);
    this->_name = clapTrap._name;
    this->_hitPoint = clapTrap._hitPoint;
    this->_energyPoint = clapTrap._energyPoint;
    this->_attackDamage = clapTrap._attackDamage;
    return (*this);
}

bool ClapTrap::checkEnergyPointLock(ClapTrap &clapTrap)
{
    if (clapTrap._energyPoint < 1)
    {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to attack." << std::endl;
        return (0);
    }
    return (1);
}

bool ClapTrap::checkDeadLock(ClapTrap &clapTrap)
{
    if (clapTrap._hitPoint < 1)
    {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to attack." << std::endl;
        return (0);
    }
    return (1);
}

ClapTrap::~ClapTrap()
{
}

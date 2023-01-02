#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
    this->_name = "default";
    std::cout << "ClapTrap " << this->_name << " constructor called." << std::endl;
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
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->checkEnergyPointLock(*this))
        return;
    if (amount > _hitPoint)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->checkEnergyPointLock(*this))
        return;
    this->_energyPoint--;
    this->_hitPoint += amount;
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
}

void ClapTrap::textPrint(ClapTrap &clapTrap){
    std::cout << clapTrap._name << }

ClapTrap::~ClapTrap()
{
}

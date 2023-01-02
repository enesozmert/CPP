#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &clapTrap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        bool checkEnergyPointLock(ClapTrap &clapTrap);
        bool checkDeadLock(ClapTrap &clapTrap);
        std::string getName();
        ~ClapTrap();
};

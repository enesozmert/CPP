#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoint;
        int _energyPoint;
        int _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        bool checkEnergyPointLock(ClapTrap &clapTrap);
        bool checkDeadLock(ClapTrap &clapTrap);
        void textPrint(ClapTrap &clapTrap);
        ~ClapTrap();
};

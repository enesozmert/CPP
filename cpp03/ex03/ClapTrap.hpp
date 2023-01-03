#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        bool _checkEnergyPointLock(ClapTrap &clapTrap, std::string action);
        bool _checkDeadLock(ClapTrap &clapTrap, std::string action);
        void _impossibleAction(std::string action, std::string color, std::string reason) const;
        void _showStats(void) const;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &clapTrap);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttackDamage(unsigned int damage);
        unsigned int getAttackDamage(void);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        std::string	_embedName(void) const;
        virtual ~ClapTrap();
};

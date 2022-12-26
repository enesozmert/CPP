#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
    if (this->weapon == NULL || this->weapon->getType().empty())
        std::cout << this->name << " Has no weapon " << std::endl;
    else
        std::cout << this->name << " Attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
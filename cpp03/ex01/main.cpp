#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clapTrap("Clappy");
	ScavTrap scavTrap("Scavvy");
	
	scavTrap.attack("random human");
	clapTrap.attack("random human");
	return (0);
}
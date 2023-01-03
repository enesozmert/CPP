#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	fragTrap("Fraggy");
	ScavTrap	scavTrap("Scavvy");
	
	scavTrap.attack("random human");
	scavTrap.guardGate();
	fragTrap.attack("random alien");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(30);
	fragTrap.takeDamage(80);
	return (0);
}
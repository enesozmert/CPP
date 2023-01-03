#include "ClapTrap.hpp"
#define SIZE 52

int	main(void)
{
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << "----testing member functions----" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		ClapTrap clapTrap1("name1");
		ClapTrap clapTrap2;


		clapTrap2 = clapTrap1;
		clapTrap2.setAttackDamage(5);
		clapTrap2.attack("enemy1");
		clapTrap2.takeDamage(1);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.beRepaired(10);
		clapTrap2.takeDamage(1);
	}
	return (0);
}
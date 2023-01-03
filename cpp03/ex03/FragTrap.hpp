#pragma once

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		void	highFivesGuys(void) const;
		FragTrap	&operator=(const FragTrap &fragTrap);
		~FragTrap();
};
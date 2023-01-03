#pragma once

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap &diamondtrap );
		DiamondTrap( std::string name );
		DiamondTrap	&operator=( const DiamondTrap &diamondtrap );
		void	whoAmI( void );
		~DiamondTrap();
};
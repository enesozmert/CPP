#pragma once

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>
# include "RandomString.hpp"

class Brain
{
    protected: 
		std::string	_ideas[100];
    public:
		Brain();
		Brain(const Brain &brain);
		void	printFirstIdeas(void) const;
		Brain &operator=(const Brain &brain);
		~Brain();
};
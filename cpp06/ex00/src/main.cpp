#include "Convert.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
	{
		std::cout << "Use ./convert litteralValue" << std::endl;
		return (1);
	}
	Convert	conv(av[1]);
	std::cout << conv;
}
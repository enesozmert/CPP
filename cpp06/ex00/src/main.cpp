#include "Convert.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
	{
		std::cout << "Use ./convert litteralValue" << std::endl;
		return (1);
	}
	Convert	convert(av[1]);

	std::cout << convert;
}
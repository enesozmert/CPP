#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
    std::string argv1(argv[1]);
    if (argc != 2)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}
    harl.complain(argv1);
    return 0;
}

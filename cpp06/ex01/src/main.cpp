#include <iostream>
#include "Data.hpp"

int main()
{
	srand(time(0));
	void *raw = serialize();
	Data *data = deserialize(raw);

	std::cout << raw << '\n';
	std::cout << *(data->s1) << '\n';
	std::cout << data->n << '\n';
	std::cout << *(data->s2) << '\n';
}
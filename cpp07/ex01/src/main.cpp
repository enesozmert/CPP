#include "iter.hpp"

int main()
{
	int array[5] = {1, 3, 2, 7, 8};
	iter(array, 5, printData);
	std::cout << std::endl;
	std::string arr[6] = {"a", "b", "c", "d", "e", "f"};
	iter(arr, 6, printData2);
}
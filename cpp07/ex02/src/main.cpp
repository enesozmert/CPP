#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **)
{
	{
		Array<int> numbers(750);
		int *mirror = new int[750];
		(void)mirror;
		srand(time(NULL));
		for (int i = 0; i < 750; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		// SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete[] mirror;
	}
	{
		std::cout << "-------------------" << std::endl;
		Array<float> fArray(5);
		float a = 1.2f;
		for(int i = 0; i < 5; i++)
		{
			fArray[i] = a;
			a += 0.666f;
		}
		Array<float>b(fArray);
		for (int i = 0; i < 5; i++)
			std::cout << b[i] << std::endl;
	}
	{
		std::cout << "-------------------" << std::endl;
		Array<char> cArray(5);
		char a = 'a';
		for(int i = 0; i < 5; i++)
		{
			cArray[i] = a;
			a++;
		}
		Array<char> cArray2 = cArray;
		for (int i = 0; i < 5; i++)
			std::cout << cArray2[i] << std::endl;
	}
}
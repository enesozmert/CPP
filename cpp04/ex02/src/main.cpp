#include <iomanip>
#include "Dog.hpp"
#include "Cat.hpp"

static void	testLeaks(void)
{
	const AAnimal	*dog = new Dog();
	const AAnimal	*cat = new Cat();

	delete dog;
	delete cat;
}

static void	testDeepCopy(void)
{
	Dog	dog1;
	Dog	dog2;

	dog1.printIdeas();
	dog2.printIdeas();

	dog2 = dog1;
	std::cout << std::endl << "After assignation :" << std::endl;
	dog1.printIdeas();
	dog2.printIdeas();

	std::cout << std::endl;

	Cat	cat1;
	Cat	cat2(cat1);

	cat1.printIdeas();
	cat2.printIdeas();
}

static void	testSubject(int size)
{
	AAnimal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}

	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}

int	main(void)
{
	srand((unsigned int)time(NULL));
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "---------------TESTSUBJECT-----------------" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	testSubject(5);
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "---------------TESTLEAKS-----------------" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	testLeaks();
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "---------------DEEPCOPY-----------------" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	testDeepCopy();
	return (0);
}
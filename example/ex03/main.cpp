#include <iostream>
#include "car.hpp"

int main()
{
    Car car1;
    std::string name;

    std::cin >> name;
    car1.setCarName(name);
    std::cout << car1.getCarName() << std::endl;
}
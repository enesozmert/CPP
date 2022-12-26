#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
class Car
{
private:
    std::string name;

public:
    Car();
    ~Car();
    void setCarName(std::string name)
    {
        this->name = name;
    }
    std::string getCarName()
    {
        return (this->name);
    }
};

Car::Car()
{
    std::cout << "new car created " + name << std::endl;
}

Car::~Car()
{
    std::cout << "new car end " + name << std::endl;
}

#endif
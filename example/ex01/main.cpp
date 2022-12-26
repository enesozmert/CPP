#include <iostream>

class Calculate
{
    public:
        int height;
        int wight;
        int area;
    
    void start()
    {
        std::cout << "Height ? : " << std::endl;
        std::cin >> height;
        std::cout << "Wight ? : " << std::endl;
        std::cin >> wight;
    }

    void calculate()
    {
        area = height * wight;
        std::cout << area << std::endl;
    }
};

int main()
{
    Calculate calculate;

    calculate.start();
    calculate.calculate();
}
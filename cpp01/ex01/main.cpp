#include "Zombie.hpp"

int atoi(std::string text)
{
    int i;
    long int calc;
    int result;

    i = 0;
    if (text.empty())
        return (-1);
    text.erase(0, text.find_first_not_of(" \t\v\f\r"));
    while (std::isspace(text[text.length() - 1]))
        text.erase(text.find_last_not_of(" \t\v\r\f") + 1, text[text.length() - 1]);
    while (text[i])
    {
        if (text[i] < '0' || text[i] > '9')
        {
            std::cout << "Please enter a valid number >" << std::endl;
            calc = 0;
            break;
        }
        calc = calc * 10 + (text[i] - '0');
        if (calc > INT_MAX || calc < INT_MIN)
        {
            std::cout << "There must be a number between INT_MAX-INT_MIN >" << std::endl;
            calc = 0;
            break;
        }
        i++;
    }
    if (calc > 0)
    {
        result = static_cast<int>(calc);
        return (result);
    }
    return (-1);
}

int getN(void)
{
    int n;
    std::string text;

    n = 0;
    while (1)
    {
        std::cout << "Number of N : " << std::endl;
        if (!(std::getline(std::cin, text)))
            exit(1);
        if (std::cin.eof())
            exit(1);
        n = atoi(text);
        if (n > 0)
            return (n);
    }
    return (-1);
}

std::string getName(void)
{
    std::string name;

    while (1)
    {
        std::cout << "Name the zombie : " << std::endl;
        if (!(std::getline(std::cin, name)))
            exit(1);
        if (std::cin.eof())
            exit(1);
        if (name.empty())
            continue;
        else
            break;
    }
    return (name);
}

int main()
{
    int i;
    int n;
    Zombie *zombies;
    std::string name;

    i = -1;
    n = getN();
    if (n == -1)
        std::cout << "error" << std::endl;
    name = getName();
    zombies = zombieHorde(n, name);
    while (++i < n)
        zombies[i].announce();
    return (0);
}

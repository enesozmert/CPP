#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    i = -1;
    std::string names[N];
    Zombie *newZombies = new Zombie[N];
    while (++i < N)
        newZombies[i].setName(name);
    return (newZombies);
}

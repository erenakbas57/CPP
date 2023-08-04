#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name)
{
    Zombie *add;
    add = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        add[i].set_name(name);
        i++;
    }
    return (0);
}
#include "Zombie.hpp"

int main()
{
    Zombie *asd;
    asd = zombieHorde(10, "EREN");

    for (int i = 0; i < 10; i++)
    {
        asd[i].announce();
    } 
}
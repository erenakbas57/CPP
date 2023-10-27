#include "Zombie.hpp"

int main()
{
    randomChump("ahmet");
    Zombie *asd;
    asd = newZombie("eren");
    asd->set_name("salih");
    asd->announce();
    delete asd;

}
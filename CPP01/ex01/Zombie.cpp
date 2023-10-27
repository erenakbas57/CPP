#include "Zombie.hpp"

void    Zombie::announce(){
    std::cout << Name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(){
    std::cout << Name << " is died.\n";
}

Zombie::Zombie(){

}

void    Zombie::set_name(std::string str)
{
    this->Name = str;
}

std::string Zombie::get_name()
{
    return (this->Name);
}

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
    return (add);
}
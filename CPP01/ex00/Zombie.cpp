#include "Zombie.hpp"

void    Zombie::announce(){
    std::cout << Name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(){
    std::cout << Name << " is died.\n";
}

Zombie::Zombie(){

}

void Zombie::set_name(std::string str)
{
    this->Name = str;
}

std::string Zombie::get_name()
{
    return (this->Name);
}

void randomChump(std::string name){
    Zombie add;
    add.set_name(name);
    add.announce();
}

Zombie* newZombie(std::string name){
    Zombie *add = new Zombie();
    add->set_name(name);
    return (add);
}
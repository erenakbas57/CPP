#include "Zombie.hpp"

void randomChump(std::string name){
    Zombie *add;
    add = new Zombie[1];
    add->set_name(name);
    add->announce();
}
#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie *add = new Zombie[1];
    add->set_name(name);
    return (add);
}
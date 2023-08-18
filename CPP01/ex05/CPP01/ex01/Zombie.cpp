#include "Zombie.hpp"

void    Zombie::announce(){
    std::cout << Name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(){
    std::cout << Name << " is died.\n";
}

Zombie::Zombie(){

}
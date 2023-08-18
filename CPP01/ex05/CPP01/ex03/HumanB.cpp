#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack(){
    std::cout << name << " attacks with their " << gun->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& type){
    gun = &type;
}
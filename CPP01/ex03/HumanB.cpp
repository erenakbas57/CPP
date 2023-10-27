#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string str)
{
    this->name = str;
    this->gun = NULL;
}

void HumanB::attack(){
    if (gun)
        std::cout << name << " attacks with their " << gun->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& type){
    gun = &type;
}
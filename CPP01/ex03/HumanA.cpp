#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string str, Weapon& new_gun) : name(str), gun(new_gun)
{
    
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << gun.getType() << std::endl;
}
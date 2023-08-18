#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack(){
    std::cout << name << " attacks with their " << gun.getType() << std::endl;
}
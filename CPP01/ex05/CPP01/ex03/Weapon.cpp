#include "Weapon.hpp"

const std::string& Weapon::getType(){
    return (type);
}

void    Weapon::setType(std::string str){
    type = str;
}
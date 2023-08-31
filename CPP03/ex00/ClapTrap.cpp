#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->name = "Eren";
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    cout << this->name + " ClapTrap is created.";
}

ClapTrap::ClapTrap(string str){
    this->name = str;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    cout << this->name + " ClapTrap is created.";
}

ClapTrap::~ClapTrap(){
    cout << this->name + " ClapTrap is destroyed.";
}
        
ClapTrap::ClapTrap(const ClapTrap& new_cpy){
    this->health = new_cpy.health;
    this->energy = new_cpy.energy;
    this->damage = new_cpy.damage;
    cout << this->name + " ClapTrap is copied.";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    this->health = other.health;
    this->energy = other.energy;
    this->damage = other.damage;
    cout << this->name + " ClapTrap ran copy assigment.";
    return (*this);
}

void ClapTrap::attack(const std::string& target){

}

void ClapTrap::takeDamage(unsigned int amount){

}

void ClapTrap::beRepaired(unsigned int amount){

}
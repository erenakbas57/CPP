#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    this->name = "NPC";
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "(CHILD)ScavTrap " << this->name + " is created.\n";
}

ScavTrap::ScavTrap(std::string str){
    this->name = str;
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "(CHILD)ScavTrap " << this->name + " is created.\n";
}

ScavTrap::~ScavTrap(){
    std::cout << "(CHILD)ScavTrap " << this->name + " is destroyed.\n";
}
        
ScavTrap::ScavTrap(const ScavTrap& new_cpy){
    *this = new_cpy;
    std::cout << "(CHILD)ScavTrap " << this->name + " is copied.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    this->name = other.name + "(copy)";
    this->health = other.health;
    this->energy = other.energy;
    this->damage = other.damage;
    std::cout << "(CHILD)ScavTrap " << this->name + " ran copy assigment.\n";
    return (*this);
}

void ScavTrap::attack(const std::string& target){
    if (energy == 0 || health == 0)
        std::cout << "(CHILD)ScavTrap " << name << " is dead.\n";
    else{
        energy--;
        std::cout << "(CHILD)ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
}

void ScavTrap::guardGate(){
    std::cout << "(CHILD)ScavTrap " << name << " entered Gate keeper mode\n";
}
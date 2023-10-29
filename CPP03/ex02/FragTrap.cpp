#include "FragTrap.hpp"

FragTrap::FragTrap(){
    this->name = "NPC";
    this->health = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "(CHILD)FragTrap " << this->name + " is created.\n";
}

FragTrap::FragTrap(std::string str){
    this->name = str;
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "(CHILD)FragTrap " << this->name + " is created.\n";
}

FragTrap::~FragTrap(){
    std::cout << "(CHILD)FragTrap " << this->name + " is destroyed.\n";
}
        
FragTrap::FragTrap(const FragTrap& new_cpy){
    *this = new_cpy;
    std::cout << "(CHILD)FragTrap " << this->name + " is copied.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    this->name = other.name + "(copy)";
    this->health = other.health;
    this->energy = other.energy;
    this->damage = other.damage;
    std::cout << "(CHILD)FragTrap " << this->name + " ran copy assigment.\n";
    return (*this);
}

void FragTrap::attack(const std::string& target){
    if (energy == 0 || health == 0)
        std::cout << "(CHILD)FragTrap " << name << " is dead.\n";
    else{
        energy--;
        std::cout << "(CHILD)FragTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
}

void FragTrap::highFivesGuys(){
    std::cout << "(CHILD)FragTrap " << name << " requests high fives.\n";
}
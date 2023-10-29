#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->name = "NPC";
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << "(PARENT)ClapTrap " << this->name + " is created.\n";
}

ClapTrap::ClapTrap(std::string str){
    this->name = str;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << "(PARENT)ClapTrap " << this->name + " is created.\n";
}

ClapTrap::~ClapTrap(){
    std::cout << "(PARENT)ClapTrap " << this->name + " is destroyed.\n";
}
        
ClapTrap::ClapTrap(const ClapTrap& new_cpy){
    *this = new_cpy;
    std::cout << "(PARENT)ClapTrap " << this->name + " is copied.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    this->name = other.name + "(copy)";
    this->health = other.health;
    this->energy = other.energy;
    this->damage = other.damage;
    std::cout << "(PARENT)ClapTrap " << this->name + " ran copy assigment.\n";
    return (*this);
}

void ClapTrap::attack(const std::string& target){
    if (energy == 0 || health == 0)
        std::cout << "(PARENT)ClapTrap " << name << " is dead.\n";
    else{
        energy--;
        std::cout << "(PARENT)ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (energy == 0 || health <= amount)
        std::cout << "(PARENT)ClapTrap " << name << " take " << health << " points of damage and died.\n";
    else{
        this->health -= amount;
        std::cout << "(PARENT)ClapTrap " << name << " take " << amount << " points of damage.\n";

    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy == 0 || health == 0)
        std::cout << "(PARENT)ClapTrap "  <<name << " is dead.\n";
    else{
        health += amount;
        energy--;
        std::cout << "(PARENT)ClapTrap " << name << " repaired himself by " << amount << " points and current health points is " << health << std::endl;
    }
}
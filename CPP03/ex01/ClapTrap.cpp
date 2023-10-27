#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->name = "NPC";
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << this->name + " is created.\n";
}

ClapTrap::ClapTrap(std::string str){
    this->name = str;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << this->name + " is created.\n";
}

ClapTrap::~ClapTrap(){
    std::cout << this->name + " is destroyed.\n";
}
        
ClapTrap::ClapTrap(const ClapTrap& new_cpy){
    this->name = "Copy " + new_cpy.name;
    this->health = new_cpy.health;
    this->energy = new_cpy.energy;
    this->damage = new_cpy.damage;
    std::cout << this->name + " is copied.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    this->health = other.health;
    this->energy = other.energy;
    this->damage = other.damage;
    std::cout << this->name + " ran copy assigment.\n";
    return (*this);
}

void ClapTrap::attack(const std::string& target){
    if (energy == 0 || health == 0)
        std::cout << name << " is dead.\n";
    else{
        energy--;
        std::cout << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (energy == 0 || health == 0)
        std::cout << name << " is dead.\n";
    else{
        this->health -= amount;
        std::cout << name << " take damage " << amount << " points.\n";
        if (health > 0)
        {
            std::cout << name << " has " << health <<  " points of health left.\n";
        }
        else
            std::cout << name << " died because " << name << " took damage " << amount << " points\n"; 
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy == 0 || health == 0)
        std::cout << name << " is dead.\n";
    else{
        health += amount;
        energy--;
        std::cout << name << " repaired himself by " << amount << " points and current health points is " << health << std::endl;
    }
}
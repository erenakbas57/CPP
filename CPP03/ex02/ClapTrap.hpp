#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string     name;
        unsigned int    health;
        unsigned int    energy;
        unsigned int    damage;
    public:
        ClapTrap();
        ClapTrap(std::string str);
        ~ClapTrap();
        ClapTrap(const ClapTrap& new_cpy);
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
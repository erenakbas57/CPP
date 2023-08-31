#ifndef CLAPTRAP_HPP
#define CLAPTRAP.HPP

#include <iostream>
using std::cout;
using std::string;
using std::endl;

class ClapTrap{
    private:
        string  name;
        int     health;
        int     energy;
        int     damage;
    public:
        ClapTrap();
        ClapTrap(string str);
        ~ClapTrap();
        ClapTrap(const ClapTrap& new_cpy);
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};




#endif
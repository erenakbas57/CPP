#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string  Name;
    
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void set_name(std::string str);
        std::string get_name();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
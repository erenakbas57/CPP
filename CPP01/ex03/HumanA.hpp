#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon      gun;
    public:
        HumanA(std::string str, Weapon new_gun);
        void    attack();
};

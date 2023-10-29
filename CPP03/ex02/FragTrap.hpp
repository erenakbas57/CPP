#ifndef FragTRAP_HPP
#define FragTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string str);
        ~FragTrap();
        FragTrap(const FragTrap& new_cpy);
        FragTrap& operator=(const FragTrap& other);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap john("John Doe");
	ClapTrap chuck("Chuck Norris");
	ScavTrap foreign;
	foreign = john;

	john.attack("Chuck Norris");
	chuck.takeDamage(0);
	chuck.takeDamage(2);
	chuck.beRepaired(2);
	chuck.takeDamage(10);
	john.takeDamage(50);
	foreign.attack("John Doe");
	foreign.guardGate();
	return 0;
}
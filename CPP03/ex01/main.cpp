#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap a;
	ClapTrap b("Kevser");
	ClapTrap c(b);

	a.attack("Zombie");
	b.takeDamage(2);
	b.beRepaired(10);
	a = b;
}
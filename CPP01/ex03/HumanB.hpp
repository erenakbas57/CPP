#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon*     gun;
	public:
		HumanB(std::string str);
		void    setWeapon(Weapon& type);
		void    attack();
};

#endif
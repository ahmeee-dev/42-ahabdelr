#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon weapon;

public:
	HumanA(std::string nameA, Weapon weaponA);
	void attack();
};

#endif
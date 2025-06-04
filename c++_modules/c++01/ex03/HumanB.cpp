#include "HumanB.hpp"

HumanB::HumanB(std::string nameB) {
	this->name = nameB;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon) {
	this->weapon = newWeapon.getType();
}
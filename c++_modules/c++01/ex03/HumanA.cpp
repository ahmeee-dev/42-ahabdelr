#include "HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon weaponA) : name(nameA), weapon(weaponA) {
	this->name = nameA;
	this->weapon.setType(weaponA.getType());
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScravTrap(name), ClapTrap(name + "clap_name") {
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScravTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->name << ", Diamond warrior, has fallen under magical circumstances" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &toCopy) : ClapTrap(toCopy)
 {
	this->name = toCopy.name;
	this->hitPoints = toCopy.hitPoints;
	this->energyPoints = toCopy.energyPoints;
	this->attackDamage = toCopy.attackDamage;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->name << " or " << ClapTrap::name << " and I serve only Trap's God" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScravTrap::attack(target);
}

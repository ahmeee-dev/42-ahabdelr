#include "ScravTrap.hpp"

void ScravTrap::attack(const std::string &target) {
	std::cout << "The earth is shaking, an attack to " << target << ", such a powerful attack (" << this->attackDamage << ")has been thrown by " << this->name << std::endl;
}

ScravTrap::ScravTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->name = "";
	this->attackDamage = 20;
	this->energyPoints = 50;

	std::cout << "	Bogos binted" << std::endl;
}

ScravTrap::ScravTrap(ScravTrap &toCopy) : ClapTrap(toCopy) {
	std::cout << "The Copy of a warrior has risen under the name of " << name << std::endl;
}

ScravTrap::ScravTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->name = name;
	this->attackDamage = 20;
	this->energyPoints = 50;

	std::cout << "	Bogos binted" << std::endl;
}

ScravTrap::~ScravTrap() {
	std::cout << this->name << "Has been destroyed by malicious forces" << std::endl;
}

void ScravTrap::guardGate() {
	std::cout << "Attack is for battles, defense in for was, and " << this->name << " knows it and goes into GateKeeper Mode" << std::endl;
}


ScravTrap& ScravTrap::operator= (ScravTrap &rhs) {
	if (this != &rhs)
	{
		this->name = rhs.name;
	}
	return (*this);
}

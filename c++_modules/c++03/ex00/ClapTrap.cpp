#include "ClapTrap.hpp"

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

ClapTrap::ClapTrap(std::string name) : name(name) {
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "A New warrior has risen under the name of " << name << std::endl;
}

ClapTrap::ClapTrap() : name("") {
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "A New warrior has risen under no name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &toCopy) : name(toCopy.name) {
	this->hitPoints = toCopy.hitPoints;
	this->energyPoints = toCopy.energyPoints;
	this->attackDamage = toCopy.attackDamage;
	std::cout << "The Copy of a warrior has risen under the name of " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "The great " << name << " has fallen on the field" << std::endl;
}

ClapTrap& ClapTrap::operator= (ClapTrap &rhs) {
	if (this != &rhs)
	{
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
		this->name = rhs.name;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (this->energyPoints > 0)
	{
		std::cout << target << " has been attacked for " << this->attackDamage << " points of damage from " << this->name << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0)
	{
		std::cout << this->name << " took " << amount << "points of damage" << std::endl;
		this->hitPoints -= amount;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is dead" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0)
	{
		std::cout << this->name << "Was kissed from the goddes of Luck and gained " << amount << " hit points" << std::endl;
	}
}

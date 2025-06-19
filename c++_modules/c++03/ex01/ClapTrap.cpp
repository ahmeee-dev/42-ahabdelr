#include "ClapTrap.hpp"

void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);

ClapTrap::ClapTrap(std::string name) : name(name) {
	attackDamage = 0;
	energyPoints = 10;
	hitPoints = 10;
	std::cout << "A New warrior has risen under the name of " << name << std::endl;
}

ClapTrap::ClapTrap() : name("") {
	attackDamage = 0;
	energyPoints = 10;
	hitPoints = 10;
	std::cout << "A New warrior has risen under no name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &toCopy) : name(toCopy.name) {
	this->attackDamage = toCopy.attackDamage;
	this->energyPoints = toCopy.energyPoints;
	this->hitPoints = toCopy.hitPoints;
	std::cout << "The Copy of a warrior has risen under the name of " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "The great " << name << " has fallen on the field" << std::endl;
}

ClapTrap& ClapTrap::operator= (ClapTrap &rhs) {
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->attackDamage = rhs.attackDamage;
		this->energyPoints = rhs.energyPoints;
		this->hitPoints = rhs.hitPoints;
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
		std::cout << this->name << " took " << amount << " points of damage" << std::endl;
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

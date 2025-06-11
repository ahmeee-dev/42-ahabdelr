#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "'I am a warrior of Frag' said the newborn." << std::endl;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::~FragTrap() {
	std::cout << this->name << " warrior of Frag has fallen under magical circumstances" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("") {
	std::cout << "'I am a warrior of Frag' said the nameless newborn." << std::endl;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::FragTrap(FragTrap &toCopy) : ClapTrap(toCopy) {
	std::cout << "The Copy of a warrior has risen under the name of " << name << std::endl;
}

FragTrap &FragTrap::operator =(FragTrap &rhs) {
	if (this != &rhs)
	{
		this->name = rhs.name;
	}
	return (*this);
}

void FragTrap::highFiveGuys(void) {
	std::cout << this->name << "'s soul is asking for honor, come give him, brats" << std::endl;
}
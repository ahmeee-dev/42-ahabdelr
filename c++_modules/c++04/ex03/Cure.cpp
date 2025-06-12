#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	this->type = "cure";
	std::cout << "Cure has been created" << std::endl;
}

Cure::~Cure() {
	std::cout << "cure has been destroyed" << std::endl;
}


Cure::Cure(Cure &toCopy) {
	std::cout << "Cure copied" << std::endl;
	this->type = toCopy.type;
}

Cure &Cure::operator=(Cure const &rhs) {
	return *this;
}

Cure *Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.name << "'s wounds *" << std::endl;
}
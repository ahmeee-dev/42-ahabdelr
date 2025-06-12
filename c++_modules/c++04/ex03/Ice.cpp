#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	this->type = "ice";
	std::cout << "Ice has been created" << std::endl;
}

Ice::~Ice() {
	std::cout << "ice has been destroyed" << std::endl;
}


Ice::Ice(Ice &toCopy) {
	std::cout << "Ice copied" << std::endl;
	this->type = toCopy.type;
}

Ice &Ice::operator=(Ice const &rhs) {
	return *this;
}

Ice *Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}
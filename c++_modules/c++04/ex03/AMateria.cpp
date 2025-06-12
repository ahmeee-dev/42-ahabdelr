#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) {
	std::cout << "Abstract Materia Class created" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
	std::cout << "Abstract Materia Class destroyed" << std::endl;
}

AMateria::AMateria() {
	std::cout << "Empty Abstract Materia Class created" << std::endl;
	this->type = "";
}

AMateria::AMateria(AMateria &toCopy) {
	std::cout << "Abstract Materia Class copied" << std::endl;
	this->type = toCopy.type;
}

std::string const &AMateria::getType() const {
	return (this->type);
}

//use is still to implement

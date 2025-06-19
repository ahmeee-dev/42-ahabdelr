#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "Shalom";
};

WrongAnimal::~WrongAnimal() {};


WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs) {
std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return (*this);
};

void WrongAnimal::getType() {
	std::cout << this->type << std::endl;
}
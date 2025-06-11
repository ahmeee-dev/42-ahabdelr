#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "Shalom";
};

WrongAnimal::~WrongAnimal() {};

WrongAnimal::WrongAnimal(WrongAnimal &toCopy) {};

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs) {
	return (*this);
};

void WrongAnimal::getType() {
	std::cout << this->type << std::endl;
}
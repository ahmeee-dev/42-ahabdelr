#include "Animal.hpp"

Animal::Animal() {
	this->type = "";
};

Animal::~Animal() {};

Animal::Animal(Animal &toCopy) {};

Animal &Animal::operator=(Animal &rhs) {
	return (*this);
};

void Animal::getType() {
	std::cout << this->type << std::endl;
}
#include "Animal.hpp"

Animal::Animal() {
	this->type = "";
};

Animal::~Animal() {};


Animal &Animal::operator=(Animal &rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return (*this);
};

void Animal::getType() {
	std::cout << this->type << std::endl;
}
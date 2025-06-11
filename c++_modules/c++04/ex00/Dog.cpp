#include "Dog.hpp"


Dog::Dog() : Animal() {
	this->type = "Dog";
}

Dog::~Dog() {};

Dog::Dog(Dog &toCopy) {
	this->type = toCopy.type;
};

Dog &Dog::operator=(Dog &rhs) {
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void Dog::makeSound() {
	std::cout << "Bau fratello, Bau..." << std::endl;
}
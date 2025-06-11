#include "Dog.hpp"


Dog::Dog() : Animal() {
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Sì, è NATO un CANE" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Sì, è MORTO un CANE" << std::endl;
};

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
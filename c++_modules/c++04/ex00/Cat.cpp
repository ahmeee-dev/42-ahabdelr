#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
}

Cat::~Cat() {};

Cat::Cat(Cat &toCopy) {
	this->type = toCopy.type;
};

Cat &Cat::operator=(Cat &rhs) {
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void Cat::makeSound() {
	std::cout << "Miao fratello, Miao..." << std::endl;
}
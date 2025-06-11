#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Sì, è NATO un GATTO" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Sì, è MORTO un GATTO" << std::endl;

};

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
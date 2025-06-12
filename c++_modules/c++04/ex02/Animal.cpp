#include "Animal.hpp"

Animal::Animal() {
	this->type = "";
	std::cout << "Sì, è NATO un ANIMALE" << std::endl;
};

Animal::~Animal() {
	std::cout << "Sì, è MORTO un ANIMALE" << std::endl;
};

Animal::Animal(Animal &toCopy) {};

Animal &Animal::operator=(Animal &rhs) {
	return (*this);
};

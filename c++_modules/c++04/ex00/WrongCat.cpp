#include "WrongCat.hpp"



WrongCat::WrongCat() : WrongAnimal() {
	this->type = "Mucca";
}

WrongCat::~WrongCat() {};

WrongCat::WrongCat(WrongCat &toCopy) {
	this->type = toCopy.type;
};

WrongCat &WrongCat::operator=(WrongCat &rhs) {
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void WrongCat::makeSound() {
	std::cout << "[Fa un tiro...] Astagfhrullah fratello [Espira...] Astagfhrullah." << std::endl;
}
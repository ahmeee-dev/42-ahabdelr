#include "WrongCat.hpp"



WrongCat::WrongCat() : WrongAnimal() {
	this->type = "Mucca";
	std::cout << "Sì, è NATA una MUCCA" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Sì, è MORTA una MUCCA" << std::endl;
};

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
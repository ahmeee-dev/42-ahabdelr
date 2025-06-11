#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "Shalom";
	std::cout << "Sì, è NATO un COSO STRANO" << std::endl;

};

WrongAnimal::~WrongAnimal() {
	std::cout << "Sì, è MORTO un COSO STRANO" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal &toCopy) {};

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs) {
	return (*this);
};

void WrongAnimal::getType() {
	std::cout << this->type << std::endl;
}
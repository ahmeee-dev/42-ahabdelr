#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string Weapon::getType() {
	const std::string &ref = this->type;
	return (ref);
}

void Weapon::setType(std::string newType) {
	this->type = newType;
	return;
}
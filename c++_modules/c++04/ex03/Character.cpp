#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] != NULL)
			delete (this->inventory[i]);
	}
}

Character::Character(Character &toCopy) {
	for (int i = 0; i < 4; i++){
		this->inventory[i] = toCopy.inventory[i];
	}}

Character &Character::operator=(Character const &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++){
			this->inventory[i] = rhs.inventory[i];
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] == NULL){
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] != NULL){
		this->dropped[this->droppedCount] = this->inventory[idx];
		this->droppedCount++;
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
/*
	Ancora da inserire
	
		void use(int idx, ICharacter& target);
*/
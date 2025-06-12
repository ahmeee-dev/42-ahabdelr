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

/*
	Ancora da inserire
	
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
*/
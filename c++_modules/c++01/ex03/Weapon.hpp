#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon {
private:
	std::string type;
public:
	Weapon(std::string type);
	Weapon();
	~Weapon();
	const std::string getType();
	void setType(std::string newType);
};

#endif
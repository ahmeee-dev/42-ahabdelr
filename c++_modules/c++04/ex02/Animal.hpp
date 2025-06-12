#ifndef ANIMAL_H
# define ANIMAL_H
#include <iostream>
#include <string.h>
#include "Brain.hpp"

class Brain;

class Animal {
	protected:
		Brain *brain;
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal &toCopy);
		Animal &operator=(Animal &rhs);
		virtual void getType() = 0;
};

#endif
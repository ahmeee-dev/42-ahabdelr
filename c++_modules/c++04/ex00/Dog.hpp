#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		~Dog();
		Dog(Dog &toCopy);
		Dog &operator=(Dog &rhs);
		void makeSound();
};

#endif
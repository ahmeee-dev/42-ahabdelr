#ifndef ANIMAL_H
# define ANIMAL_H
#include <iostream>
#include <string.h>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		Animal(Animal &toCopy);
		Animal &operator=(Animal &rhs);
		void getType();
};

#endif
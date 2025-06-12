#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat &toCopy);
		WrongCat &operator=(WrongCat &rhs);
		void makeSound();
};

#endif
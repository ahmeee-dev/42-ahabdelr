#ifndef CAT_H
# define CAT_H

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		Cat(Cat &toCopy);
		Cat &operator=(Cat &rhs);
		void makeSound();
};

#endif
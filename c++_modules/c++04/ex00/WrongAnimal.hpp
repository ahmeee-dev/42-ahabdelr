#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
#include <iostream>
#include <string.h>


class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal &toCopy);
		WrongAnimal &operator=(WrongAnimal &rhs);
		void getType();
};

#endif

#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

Brain::Brain() {
	std::cout << "Sì, è NATO un CERVELLO" << std::endl;
}

Brain::~Brain() {
	std::cout << "Sì, è MORTO un CERVELLO" << std::endl;
};


Brain &Brain::operator=(Brain &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

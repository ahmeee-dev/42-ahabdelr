#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	Cat yugi;
	Dog astro;
	WrongCat milo;
	Animal *cuozzi[100];
	
	yugi.makeSound();
	astro.makeSound();
	milo.makeSound();
	yugi.getType();
	astro.getType();
	milo.getType();
	for (int i = 0; i < 100; i++){
		if (i < 50)
			cuozzi[i] = new Cat();
		else
			cuozzi[i] = new Dog();
	}

	for (int i = 0; i < 100; i++){
		delete cuozzi[i];
	}
}
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	Cat yugi;
	Dog astro;
	WrongCat milo;
	Animal cuozzo;
	
	yugi.makeSound();
	astro.makeSound();
	milo.makeSound();
	yugi.getType();
	astro.getType();
	milo.getType();
	cuozzo.getType();
}
#include "Array.hpp"
#include <iostream>

int main( void ) {
	Array<std::string> interi;
	for (int i = 0; i < interi.getSize(); i++) {
		interi[i] = "Mario";
	}
	try {
		std::cout << interi[1] << std::endl;
	} catch (std::out_of_range err) { std::cout << err.what() << std::endl; };
}
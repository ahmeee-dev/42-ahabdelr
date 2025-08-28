#include "Span.hpp"
#include <iostream>

int main( void ) {
	Span sp = Span(12);

	std::cout << sp.getSize() << std::endl;
	for (int i = 0; i <= 13; i++) {
		try { sp.addNumber(i); } catch (OutOfRangeException err) { std::cout << err.what() << std::endl; };
	}
	std::cout << sp.getSize() << std::endl;
}

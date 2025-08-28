#include "Span.hpp"
#include <iostream>

int main( void ) {
	Span sp = Span(5);
	Span ts = Span(3);

	sp.addNumber(6);
	sp.addNumber(3);;

	ts.addNumber(123);
	ts.addNumber(321);
	ts.addNumber(213);

	std::vector<int>::iterator tsEnd = ts.getStart() + ts.getFullness();
	sp.addMultipleNumbers<std::vector<int> >(ts.getStart(), tsEnd);

	std::cout << sp.getSize() << std::endl;
	for (int i = 0; i < sp.getFullness(); i++) {
	  	std::cout << *(sp.getStart() + i) << std::endl;
	};

	std::cout << sp.getSize() << std::endl;

	// try {
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	std::cout << sp.shortestSpan() << std::endl;
	// } catch (NoElementsException err) { std::cout << err.what() << std::endl; }

	


}

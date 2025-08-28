#include "Span.hpp"
#include <iostream>
#include <cmath>

Span::Span(uint n) {
		this->vec = std::vector<int>(n);
		size = n;
		it = this->vec.begin();
}


void Span::addNumber(int n) {
	if (this->it - this->vec.begin() == this->size)
		throw OutOfRangeException();
	*this->it = n;
	this->it++;
}

int Span::getSize() {
	return (this->vec.size());
}

int Span::getFullness() {
	return (this->it - this->vec.begin());
};

std::vector<int>::iterator Span::getStart() {
	return (this->vec.begin());
}

Span Span::shortestSpan(Span B) {
	std::vector<int>::iterator tempItB;
	std::vector<int>::iterator itB;
	std::vector<int>::iterator tempItA;
	int shortestSpan = -1;

	tempItA = this->vec.begin();
	tempItB = B.getStart();
	itB = tempItB + B.getFullness();

	if (B.getFullness() < 1 || this->getFullness() < 1)
		throw NoElementsException();
	while ((tempItA != this->it && tempItB != itB)) {
		if (abs(*this->it - *itB) < shortestSpan || shortestSpan < 0)
			shortestSpan = abs(*this->it - *itB);
	}
	return (shortestSpan);
};

Span Span::longestSpan(Span B) {
std::vector<int>::iterator tempItB;
	std::vector<int>::iterator itB;
	std::vector<int>::iterator tempItA;
	int longestSpan = -1;

	tempItA = this->vec.begin();
	tempItB = B.getStart();
	itB = tempItB + B.getFullness();

	if (B.getFullness() < 1 || this->getFullness() < 1)
		throw NoElementsException();
	while ((tempItA != this->it && tempItB != itB)) {
		if (abs(*this->it - *itB) > longestSpan || longestSpan < 0)
			longestSpan = abs(*this->it - *itB);
	}
	return (longestSpan);
}
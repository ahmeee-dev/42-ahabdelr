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

int Span::shortestSpan() {
	int shortest = 2147483647;

	if (this->getFullness() < 2)
		throw (NoElementsException());

	for (int i = 0; i < this->getFullness(); i++) {
		for (int j = i + 1; j < this->getFullness(); j++) {
			if ((*this->getStart() + i + *this->getStart() + j) < shortest)
				shortest = (*this->getStart() + i + *this->getStart() + j);
		}
	}
	return (shortest);
}

int Span::longestSpan() {
	int longest = -2147483648;

	if (this->getFullness() < 2)
		throw (NoElementsException());

	for (int i = 0; i < this->getFullness(); i++) {
		for (int j = i + 1; j < this->getFullness(); j++) {
			if ((*this->getStart() + i + *this->getStart() + j) > longest)
				longest = *this->getStart() + i + *this->getStart() + j;
		}
	}
	return (longest);
}
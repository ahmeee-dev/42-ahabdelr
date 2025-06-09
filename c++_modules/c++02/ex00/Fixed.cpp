#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Defalut constructor called" << std::endl;
	this->integer = 0;
}

Fixed::Fixed(const Fixed &original) {
	this->integer = original.integer;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->integer = rhs.integer;
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->integer);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->integer = raw;
}
#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(int const integer) {
	std::cout << "Int constructor called" << std::endl;
	this->integer = integer * (1 << Fixed::fract);
}

Fixed::Fixed(float const floating) {
	std::cout << "Float constructor called" << std::endl;
	this->integer = static_cast<int>(roundf((floating) * (1 << Fixed::fract)));
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

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->integer)/ (1 << Fixed::fract));
}

int Fixed::toInt(void) const {
	return (this->integer/(1 << fract));
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->integer);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->integer = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
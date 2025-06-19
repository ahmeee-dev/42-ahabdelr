#include "Fixed.hpp"

Fixed::Fixed() {
	this->integer = 0;
	//std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(int const integer) {
	//std::cout << "Int constructor called" << std::endl;
	this->integer = integer * (1 << Fixed::fract);
}

Fixed::Fixed(float const floating) {
	//std::cout << "Float constructor called" << std::endl;
	this->integer = static_cast<int>(roundf((floating) * (1 << Fixed::fract)));
}

Fixed::Fixed(const Fixed &original) {
	this->integer = original.integer;
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &rhs) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->integer = rhs.integer;
	}
	return (*this);
}

bool Fixed::operator > (const Fixed &rhs) {
	return (this->integer > rhs.integer);
}

bool Fixed::operator <(const Fixed &rhs) {
	return (this->integer < rhs.integer);
}


bool Fixed::operator >=(const Fixed &rhs) {
	return (this->integer >= rhs.integer);
}


bool Fixed::operator <=(const Fixed &rhs) {
	return (this->integer <= rhs.integer);
}

bool Fixed::operator ==(const Fixed &rhs) {
	return (this->integer == rhs.integer);
}

bool Fixed::operator !=(const Fixed &rhs) {
	return (this->integer != rhs.integer);
}

Fixed Fixed::operator *(const Fixed &rhs) {
	Fixed result;
	result.integer = (this->integer * rhs.integer)/(1 << Fixed::fract);
	return (result);
} 

Fixed Fixed::operator +(const Fixed &rhs) {
	Fixed result;
	result.integer = this->integer + rhs.integer;
	return (result);
} 

Fixed Fixed::operator /(const Fixed &rhs) {
	Fixed result;
	result.integer = this->integer / rhs.integer;
	return (result);
} 

Fixed Fixed::operator -(const Fixed &rhs) {
	Fixed result;
	result.integer = this->integer - rhs.integer;
	return (result);
}

Fixed Fixed::operator ++() {
	this->integer += 1;
	return (*this);
}

Fixed Fixed::operator ++(int) {
	Fixed temp;
	temp.integer = this->integer;
	this->integer += 1;
	return (temp);
}

Fixed Fixed::operator --() {
	Fixed result;
	result.integer = this->integer - 1;
	return (result);
}

Fixed Fixed::operator --(int) {
	Fixed temp;
	temp.integer = this->integer;
	this->integer -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.integer > b.integer)
		return (b);
	else
		return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.integer < b.integer)
		return (b);
	else
		return (a);
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
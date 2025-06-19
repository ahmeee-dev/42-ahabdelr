#include "Point.hpp"

Point::Point(const Fixed initX, const Fixed initY) : x(initX), y(initY){
}

Point::Point() : x(0), y(0) {}

Point::Point(const Point &copyElement) : x(copyElement.x), y(copyElement.y) {}

Point::~Point() {}

Point &Point::operator =(const Point &rhs) {
	(void)rhs;
	return (*this);
}

float Point::getX() const {
	return (this->x.toFloat());
}
float Point::getY() const {
	return (this->y.toFloat());
}

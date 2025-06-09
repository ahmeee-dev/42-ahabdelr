#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		//constructors
		Point();
		Point(Fixed initX, Fixed initY);
		Point(const Point &copyElement);
		~Point();

		//overloads
		Point &operator = (const Point &rhs);

		//methods
		float getX() const;
		float getY() const;
};


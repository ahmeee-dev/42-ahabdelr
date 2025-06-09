#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float xp = point.getX();
	float yp = point.getY();
	float y1 = a.getY();
	float x1 = a.getX();
	float x2 = b.getX();
	float y2 = b.getY();
	float x3 = c.getX();
	float y3 = c.getY();
	float denominator = ((y2 - y3) * (x1 - x3)) + ((x3 - x2) * (y1 - y3));

	float alpha = (((y2 - y3) * (xp - x3)) + ((x3 - x2) * (yp - y3)))/denominator;
	float beta = (((y3 - y1) * (xp - x3)) + ((x1 - x3) * (yp - y3)))/denominator;
	float gamma = 1.0 - alpha - beta;

	return ((gamma > 0 && gamma < 1) && (beta > 0 && beta < 1) && (alpha > 0 && alpha < 1));
	
}
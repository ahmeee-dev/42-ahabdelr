#include <iostream>
#include <string.h>
#include <cmath>

class Fixed {
	private:
		int integer;
		static const int fract = 8;

	public:
	//constructors
		Fixed();
		Fixed(int const integer);
		Fixed(float const floating);
		Fixed(const Fixed &copyElement);
		~Fixed();

	//overloads
		Fixed &operator =(const Fixed &rhs);
		bool operator >(const Fixed &rhs);
		bool operator <(const Fixed &rhs);
		bool operator >=(const Fixed &rhs);
		bool operator <=(const Fixed &rhs);
		bool operator ==(const Fixed &rhs);
		bool operator !=(const Fixed &rhs);
		Fixed operator +(const Fixed &rhs);
		Fixed operator -(const Fixed &rhs);
		Fixed operator /(const Fixed &rhs);
		Fixed operator *(const Fixed &rhs);
		Fixed operator ++(int);
		Fixed operator ++();
		Fixed operator --(int);
		Fixed operator --();
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);



	//methods
		int getRawBits(void) const;
		void setRawBits(int const raw);

	//conversions
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

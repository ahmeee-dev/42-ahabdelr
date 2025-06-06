#include <iostream>
#include <string.h>
#include <cmath>

class Fixed {
	private:
		int integer;
		static const int fract = 8;

	public:
		Fixed();
		Fixed(int const integer);
		Fixed(float const floating);
		Fixed(const Fixed &copyElement);
		Fixed &operator =(const Fixed &rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#include "iostream"
#include "string.h"

class Fixed {
	private:
		int integer;
		static const int fract = 8;

	public:
		Fixed();
		Fixed(const Fixed &copyElement);
		Fixed &operator =(const Fixed &rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
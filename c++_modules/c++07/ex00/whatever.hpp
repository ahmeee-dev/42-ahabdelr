#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <stdio.h>

template<typename T>
class whatever {
	public:
		void static swap(T &a, T &b) {
			T temp;
			temp = a;
			a = b;
			b = temp;
		}

		T static min(T const &a, T const &b) {
			return (a > b ? b : a);
		}

		T static max(T const &a, T const &b) {
			return (a > b ? a : b);
		}
};

#endif
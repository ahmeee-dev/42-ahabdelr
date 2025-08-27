#include <cstddef>
#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename F>
	void static iteration(T* array, size_t len, F func ) {
		for ( size_t i = 0; i < len; i++ ) {
			func(array[i]);
		}
		return;
	}
#endif
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>


class ElementNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Couldn't find value searched");
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {

	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		if (*it == value)
			return (it);
	}
	throw (ElementNotFoundException());
}

#endif
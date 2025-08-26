#ifndef BASE_HPP
# define BASE_HPP

#include <math.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base {

	Base *generate();
	void identify(Base *p);
	virtual ~Base() {};
};

#endif
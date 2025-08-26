
#include "Base.hpp"
#include <iostream>

Base* generate() {
	Base* result;
	switch (rand() % 3) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
};

void Base::identify(Base *p) {
		if (dynamic_cast<A*>(p))

		(void)dynamic_cast<A&>(p);
}
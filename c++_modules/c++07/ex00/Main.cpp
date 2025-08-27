#include "whatever.hpp" 
#include <iostream>


int main( void ) {
	int a = 2;
	int b = 3;
	whatever<int>::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << whatever<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << whatever<int>::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	whatever<std::string>::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << whatever<std::string>::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << whatever<std::string>::max( c, d ) << std::endl;
	float e = 3.21111;
	float f = 3.21112;
	whatever<float>::swap(e, f);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << whatever<float>::min( e, f ) << std::endl;
	std::cout << "max( c, d ) = " << whatever<float>::max( e, f ) << std::endl;
	return 0;
}
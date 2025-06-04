#include <iostream>
#include <string.h>

int main() {
	std::string mario = "HI THIS IS BRAIN";
	std::string *stringPTR = &mario;
	std::string &stringREF = mario;

	std::cout << &mario << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << mario << std::endl << *stringPTR  << std::endl << stringREF << std::endl;
	return (0);
}
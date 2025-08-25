#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string str) {
	if (str == "nan") {
		std::cout << "char: " << "impossible" << std::endl; //char
		std::cout << "int: " << "impossible" << std::endl; //int
		std::cout << "float: " << "nan" << "f" << std::endl; //float
		std::cout << "double: " << "nan"<< std::endl; //double
		exit(0);
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "char: " << "impossible" << std::endl; //char
		std::cout << "int: " << "+∞" << std::endl; //int
		std::cout << "float: " << "+∞" << "f" << std::endl; //float
		std::cout << "double: " << "+∞"<< std::endl; //double
		exit(0);
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "char: " << "impossible" << std::endl; //char
		std::cout << "int: " << "-∞" << std::endl; //int
		std::cout << "float: " << "-∞" << "f" << std::endl; //float
		std::cout << "double: " << "-∞"<< std::endl; //double
		exit(0);
	}

	std::cout << std::fixed << std::setprecision(1);
		for (int letters = 0; letters <= 127; letters++) {
		if (str == std::string() + (char)letters) {
			if (letters < 33)
				std::cout << "char: Non displayable" << std::endl; //char
			else
				std::cout << "char: " << (char)letters << std::endl; //char
			std::cout << "int: " << letters << std::endl; //int
			std::cout << "float: " << (float)letters << "f" << std::endl; //float
			std::cout << "double: " << (double)letters << std::endl; //double
			exit(0);
		}
	}
	bool check = 0; //char exists
		if ((int)std::stod(str) >= 127 || (int)std::stod(str) <= 32) {
			 check = 1;
		}

	if (str.find('.') != std::string::npos)
	{
		if (str.find('f') != std::string::npos) {
			if (check == 0)
				std::cout << "char: " << (char)(int)std::stof(str) << std::endl; //char
			else
				std::cout << "char: " << "Non displayable" << std::endl;
			std::cout << "int: " << (int)std::stof(str) << std::endl; //int
			std::cout << "float: " << std::stof(str) << "f" << std::endl; //float
			std::cout << "double: " << std::stod(str) << std::endl; //double
		}
		else {
			if (check == 0)
				std::cout << "char: " << (char)(int)std::stod(str) << std::endl; //char
			else
				std::cout << "char: " << "Non displayable" << std::endl;
			std::cout << "int: " << (int)std::stod(str) << std::endl; //int
			std::cout << "float: " << std::stof(str) << "f" << std::endl; //float
			std::cout << "double: " << std::stod(str) << std::endl; //double
		}
	} else {
		if (check == 0)
			std::cout << "char: " << (char)std::stoi(str) << std::endl; //char
		else
				std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << std::stoi(str) << std::endl; //int
		std::cout << "float: " << std::stof(str) << "f" << std::endl; //float
		std::cout << "double: " << std::stod(str) << std::endl; //double
	}

}
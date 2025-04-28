#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

std::string	wrongSearchInput(std::string toFind){
	if (toFind == "")
	{
		std::cout << "Are you having fun cuh?" << std::endl;
		std::cout << "Com'on don't be a child >>>> ";
		std::getline(std::cin, toFind);
		toFind = wrongSearchInput(toFind);
	}
	return (toFind);
}

int	main(void){
	PhoneBook 	phoneBook;
	std::string	input;
	bool		alive = 1;
	int		done = 0;
	std::string	toFind;

	while (alive == 1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phoneBook.addContact(done % 8);
			done++;
		}
		if (input == "SEARCH")
		{
			phoneBook.displayContacts(done);
			std::cout << ">>>>>> ";
			std::getline(std::cin, toFind);
			if (toFind == "")
				std::cout << "Are you having fun cuh?" << std::endl;
			std::cout << "Com'on don't be a child >>>> ";
			std::getline(std::cin, toFind);
			toFind = wrongSearchInput(toFind);
			if ( done / 8 == 0 && (std::atoi(toFind.c_str()) > done % 9 || std::atoi(toFind.c_str()) <= 0))
			{
				toFind = "";
				toFind = wrongSearchInput(toFind);
			}
			phoneBook.showIstance(toFind);
		}
		if (input == "EXIT")
			alive = 0;
	}
}
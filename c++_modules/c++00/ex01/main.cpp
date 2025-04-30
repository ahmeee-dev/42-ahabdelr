#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono> 

void playMagicEffect() {
	for (int i = 0; i < 10; ++i) {
		std::cout << "*";
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Magic Noises...";
	std::cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << " It happened..." << std::endl;
}

std::string	searchInput(int done){
	std::string	toFind;
	std::getline(std::cin, toFind);
	int addNumber = std::atoi(toFind.c_str());
	if (toFind == "" || addNumber > done || addNumber < 1)
	{
		std::cout << "Are you having fun cuh?\n" << std::endl;
		std::cout << "Com'on don't be a child >>>> ";
		toFind = searchInput(done);
	}
	return (toFind);
}

int	main(void){
	PhoneBook 	phoneBook;
	std::string	input;
	bool		alive = 1;
	int		done = 0;
	int		actual = 0;
	std::string	toFind;

	srand(time(0));
	while (alive == 1)
	{
		std::cout << ">>>>>> ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phoneBook.addContact(actual);
			if (done < 8)
				done++;
			actual++;
			actual = actual % 8;
		}
		if (input == "SEARCH" && done > 0)
		{
			phoneBook.displayFunction(done);
			std::cout << "\nType an Index >> ";
			toFind = searchInput(done);
			phoneBook.showIstance(toFind);
		}
		if (input == "EXIT")
			alive = 0;
		if (input == "HELP")
		{
			phoneBook.helpFunction();
			playMagicEffect();
			done = 8;
			actual = 0;
		}
	}
}
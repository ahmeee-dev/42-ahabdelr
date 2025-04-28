#include <iostream>
#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"

void	PhoneBook::addContact(int done){
	contact[done].setFirstName();
	contact[done].setLastName();
	contact[done].setNickName();
	contact[done].setPhoneNumber();
	contact[done].setDarkestSecret();
}

void	PhoneBook::displayFunction(int done){
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < done % 7; i++)
		contact[i].displayContacts(i);
	std::cout << " ------------------------------------------- " << std::endl;
}

void	PhoneBook::showIstance(std::string index){
	contact[std::atoi(index.c_str()) - 1].displayIstance();
}


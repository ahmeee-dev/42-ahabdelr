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
	for (int i = 0; i < done; i++)
		contact[i].displayContacts(i);
	std::cout << " ------------------------------------------- " << std::endl;
}

void	PhoneBook::showIstance(std::string index){
	contact[std::atoi(index.c_str()) - 1].displayIstance();
}

void	PhoneBook::helpFunction(){
	for (int i = 0; i < 8; i++)
	{
		contact[i].randDarkestSecret();
		contact[i].randNickName();
		contact[i].randFirstName();
		contact[i].randPhoneNumber();
		contact[i].randLastName();
	}
}

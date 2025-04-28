#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>

void ContactClass::setFirstName(){
	std::cout << "First Name : ";
	getline(std::cin, firstName);
	if (firstName == "")
		setFirstName();
}

void ContactClass::setLastName(){
	std::cout << "Last Name : ";
	getline(std::cin, lastName);
	if (lastName == "")
		setLastName();
}

void ContactClass::setNickName(){
	std::cout << "Nickname : ";
	getline(std::cin, nickName);
	if (nickName == "")
		setNickName();
}

void ContactClass::setPhoneNumber(){
	std::cout << "Phone Number : ";
	getline(std::cin, phoneNumber);
	if (phoneNumber == "")
		setPhoneNumber();
}

void ContactClass::setDarkestSecret(){
	std::cout << "Darkest Secret : ";
	getline(std::cin, darkestSecret);
	if (darkestSecret == "")
		setDarkestSecret();
}


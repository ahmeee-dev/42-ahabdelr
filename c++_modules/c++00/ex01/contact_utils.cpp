#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>


std::string fixLenght(std::string str)
{
	int size = str.size();
	if (size > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	else if (size < 10)
	{
		for (int i = 0; i < 10 - size + i; i++)
			str.insert(0, " ");
	}
	return (str);
}

void	ContactClass::displayContacts(int index){
	std::cout << "|";
	std::cout << (index + 1 + '0');
	std::cout << "|";
	std::cout << fixLenght(firstName);
	std::cout << "|";
	std::cout << fixLenght(lastName);
	std::cout << "|";
	std::cout << fixLenght(nickName);
	std::cout << "|";
}

void	ContactClass::displayIstance(){
	std::cout << "> First Name: " + firstName << std::endl;
	std::cout << "> Last Name: " + lastName << std::endl;
	std::cout << "> Nickname: " + nickName << std::endl;
	std::cout << "> Phone Number: " + phoneNumber << std::endl;
	std::cout << "> Darkest Secret: " + darkestSecret << std::endl;
}
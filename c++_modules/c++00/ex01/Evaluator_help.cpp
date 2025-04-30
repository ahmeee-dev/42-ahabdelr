#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>


std::string generateRandomString(int length) {
	const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string result;

	for (int i = 0; i < length; i++) {
		result += charset[rand() % charset.length()];
	}
	return result;
}

void ContactClass::randFirstName(){
	firstName = generateRandomString(8); 
}

void ContactClass::randLastName(){
	lastName = generateRandomString(12);
}

void ContactClass::randNickName(){
	nickName = generateRandomString(6);
}

void ContactClass::randPhoneNumber(){
	const std::string digits = "0123456789";
	phoneNumber = "";
	for (int i = 0; i < 10; i++) {
		phoneNumber += digits[rand() % digits.size()];
	}
}

void ContactClass::randDarkestSecret(){
	darkestSecret = generateRandomString(15);
}
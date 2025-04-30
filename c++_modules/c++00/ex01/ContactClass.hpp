#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>

class ContactClass{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	void	setFirstName();
	void	setLastName();
	void	setNickName();
	void	setPhoneNumber();
	void	setDarkestSecret();
	void	displayContacts(int index);
	void	displayIstance();

	void	randFirstName();
	void	randLastName();
	void	randNickName();
	void	randPhoneNumber();
	void	randDarkestSecret();
};


#endif
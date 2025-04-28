#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

# include <string>
# include "ContactClass.hpp"

class PhoneBook {
private:
	ContactClass contact[8];
public:
	void	addContact(int done);
	void	displayFunction(int done);
	void	showIstance(std::string index);
};

#endif
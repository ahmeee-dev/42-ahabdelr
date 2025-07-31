#include "Intern.hpp"

AForm *Intern::createForm(std::string formName, std::string formTarget) {
	std::string types[] =  { "shrubbery creation", "robotomy request", "presidential pardon"};
	int formType = -1;
	for (int i = 0; i < 3; i++) {
		if (types[i] == formName)
			formType = i;
	}
	switch (formType)
	{
		case 0:
			std::cout << "intern creates" + formName << std::endl;
			return (new ShrubberyCreationForm (formName, formTarget));
			break;
		
		case 1:
			std::cout << "intern creates" + formName << std::endl;
			return (new RobotomyRequestForm(formName, formTarget));
			break;

		case 2:
			std::cout << "intern creates" + formName << std::endl;
			return (new PresidentialPardonForm(formName, formTarget));
			break;

		default:
			std::cout <<  "you messed up, there isn't any form named this way" << std::endl;
			return (NULL);
			break;
	}
}

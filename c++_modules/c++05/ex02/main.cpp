#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	Bureaucrat mario("Mario Draghi", 2);
	ShrubberyCreationForm bush("bush", "fire");
	RobotomyRequestForm robo("Robot", "Eusebio");
	PresidentialPardonForm pardon("Zarbon", "Darbula");

	//std::cout << mario.getGrade() << std::endl;
	//mario.signForm(bush);
	//mario.incrementGrade(131);
	std::cout << mario.getGrade() << std::endl;;
	mario.signForm(bush);
	mario.signForm(robo);
	mario.signForm(pardon);
	mario.executeForm(pardon);
	mario.executeForm(robo);
	mario.executeForm(bush);
	

	std::cout << "E dopo questo Mario si ritira" << std::endl;

	return (0);
}
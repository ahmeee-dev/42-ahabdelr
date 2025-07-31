#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void) {

	Bureaucrat mario("Mario Draghi", 138);
	ShrubberyCreationForm bush("bush", "fire");

	std::cout << mario.getGrade() << std::endl;
	mario.signForm(bush);
	mario.incrementGrade(131);
	std::cout << mario.getGrade() << std::endl;;
	mario.signForm(bush);
	mario.executeForm(bush);
	std::cout << "E dopo questo Mario si ritira" << std::endl;

	return (0);
}
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	Bureaucrat mario("Mario Draghi", 138);
	Form jobsAct("jobsAct", 7, 2);

	std::cout << mario.getGrade() << std::endl;
	mario.signForm(jobsAct);
	mario.incrementGrade(131);
	std::cout << mario.getGrade() << std::endl;;
	mario.signForm(jobsAct);
	std::cout << "E dopo questo Mario si ritira" << std::endl;

	return (0);
}
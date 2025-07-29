#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	Bureaucrat mario("Mario Draghi", 138);
	Form jobsAct("jobsAct", 7, 2);

	mario.getGrade();
	mario.signForm(jobsAct);
	mario.decrementGrade(134);
	mario.getGrade();
	mario.signForm(jobsAct);
	std::cout << "E dopo questo Mario si ritira" << std::endl;

	return (0);
}
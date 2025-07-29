#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat mario("Mario", 138);
	Bureaucrat lario("Lario", 148);
	Bureaucrat dario("Dario", 128);
	Bureaucrat pario("Pario", 158);
	
	mario.getGrade();
	lario.getGrade();
	dario.getGrade();
	pario.getGrade();

	mario.incrementGrade(2);
	mario.getGrade();
	mario.getName();
	mario.decrementGrade(2);
	mario.getGrade();

	return (0);
}
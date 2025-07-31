#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <math.h>

#define SIGN_GRADE 72
#define EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) :  AForm(name, SIGN_GRADE, EXEC_GRADE), target(target) {};

std::string RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw (RobotomyRequestForm::FormNotSignedException());
		if (executor.getGrade() > this->getGradeToExecute())
			throw (RobotomyRequestForm::GradeTooLowException());
	} catch (std::exception &err) {
			return (err.what());
		}
		specificOperation(this->target);
	return ("executed");
}

void RobotomyRequestForm::specificOperation(const std::string &target) const {

	std::cout << "BRRRRRRRRRRRRRRRRRZZZZZZZZZ-KRRRR-KRRR-BRRRZZZZRRRRRRR!" << std::endl;
	if (rand() % 2) {
		std::cout << "We couldn't robotomize " + target + " we're sorry" << std::endl;
		return;
	}
	std::cout << target + " has been romotomized!" << std::endl;
}

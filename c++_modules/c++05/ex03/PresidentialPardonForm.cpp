#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <math.h>

#define SIGN_GRADE 25
#define EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) :  AForm(name, SIGN_GRADE, EXEC_GRADE), target(target) {};

std::string PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw (PresidentialPardonForm::FormNotSignedException());
		if (executor.getGrade() > this->getGradeToExecute())
			throw (PresidentialPardonForm::GradeTooLowException());
	} catch (std::exception &err) {
			return (err.what());
		}
		specificOperation(this->target);
	return ("executed");
}

void PresidentialPardonForm::specificOperation(const std::string &target) const {
	std::cout << target + " has been pardoned by Zafod Beeblebrox!" << std::endl;
}

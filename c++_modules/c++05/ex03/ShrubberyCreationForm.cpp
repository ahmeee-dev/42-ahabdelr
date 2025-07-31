#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define SIGN_GRADE 145
#define EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) :  AForm(name, SIGN_GRADE, EXEC_GRADE), target(target) {};

std::string ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw (ShrubberyCreationForm::FormNotSignedException());
		if (executor.getGrade() > this->getGradeToExecute())
			throw (ShrubberyCreationForm::GradeTooLowException());
	} catch (std::exception &err) {
			return (err.what());
		}
		specificOperation(this->target);
	return ("executed");
}

void ShrubberyCreationForm::specificOperation(const std::string &target) const {
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file)
	{
		std::cerr << "Errore: impossibile creare il file " << filename << std::endl;
		return;
	}

	file << "           &&& &&  & &&" << std::endl;
file << "       && &\\/&\\|& ()|/ @, &&" << std::endl;
file << "       &\\/(/&/&||/& /_/)_&/_&" << std::endl;
file << "    &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
file << "   &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
file << "     &&     \\|||" << std::endl;
file << "             |||" << std::endl;
file << "             |||" << std::endl;
file << "             |||" << std::endl;
file << "       , -=-~  .-^- _" << std::endl;

	file.close();
}

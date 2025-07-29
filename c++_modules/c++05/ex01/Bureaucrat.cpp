#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	try {
		if (grade < 1)
			throw (Bureaucrat::GradeTooLowExeception());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (std::exception &ex) {
			std::cout << ex.what() << std::endl;
	}

}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat &toCopy): name(toCopy.name), grade(toCopy.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->grade = rhs.grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() {
	std::cout << this->grade << std::endl;
	return this->grade;
}

std::string Bureaucrat::getName() {
	std::cout << this->name << std::endl;
	return this->name;
}

void Bureaucrat::incrementGrade(int amount) {
	this->grade+= amount;
}

void Bureaucrat::decrementGrade(int amount) {
	this->grade-= amount;
}
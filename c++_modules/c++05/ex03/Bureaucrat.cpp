#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	try {
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
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

std::ostream& operator<<(std::ostream&os, const Bureaucrat &rhs) {
	os << rhs.getName()  <<" , bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}


int Bureaucrat::getGrade() const{
	//std::cout << this->grade << std::endl;
	return this->grade;
}

std::string Bureaucrat::getName() const{
	//std::cout << this->name << std::endl;
	return this->name;
}

void Bureaucrat::signForm(AForm &toSign) {
	try {
		std::string outcome = toSign.beSigned(*this);
		if (outcome != "")
			throw outcome;
		std::cout << this->name << " signed " << toSign.getName() << std::endl;
	} catch (std::string err) {
		std::cout << this->name << " couldn't sign " << toSign.getName() << " because " << err << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	std::string toPrint = this->name + " " + form.execute(*this) + " " + form.getName();
	std::cout << toPrint << std::endl;
}


void Bureaucrat::incrementGrade(int amount) {
	this->grade-= amount;
}

void Bureaucrat::decrementGrade(int amount) {
	this->grade+= amount;
}
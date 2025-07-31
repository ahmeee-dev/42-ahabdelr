#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	isSigned = false;
}

AForm::~AForm() {}

AForm::AForm(AForm &toCopy): name(toCopy.name), gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute) {
	this->isSigned = toCopy.getIsSigned();
}

AForm& AForm::operator =(const AForm &rhs) {
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream&os, const AForm &rhs) {
	os << rhs.getName() << ", grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " signed: " << rhs.getIsSigned() << std::endl;
	return os;
}

std::string AForm::beSigned(Bureaucrat figure) {
	try {
		if (figure.getGrade() > this->gradeToSign)
			throw (AForm::GradeTooLowException());
		else if (figure.getGrade() < 1)
			throw (AForm::GradeTooHighException());
	}
	catch (std::exception &err) {
		return err.what();
	}
	this->isSigned = true;
	return ("");
}

std::string AForm::getName() const{
	//std::cout << this->name;
	return (name);
}

int AForm::getGradeToExecute() const{
	//std::cout << this->gradeToExecute;
	return (gradeToExecute);
}

int AForm::getGradeToSign() const{
	//std::cout << this->gradeToSign;
	return (gradeToSign);
}

bool AForm::getIsSigned() const{
	//std::cout << this->isSigned;
	return (isSigned);
}
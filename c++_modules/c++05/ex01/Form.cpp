#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	isSigned = false;
}

Form::~Form() {}

Form::Form(Form &toCopy): name(toCopy.name), gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute) {
	this->isSigned = toCopy.getIsSigned();
}

Form& Form::operator =(const Form &rhs) {
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream&os, const Form &rhs) {
	os << rhs.getName() << ", grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " signed: " << rhs.getIsSigned() << std::endl;
	return os;
}

std::string Form::beSigned(Bureaucrat figure) {
	try {
		if (figure.getGrade() > this->gradeToSign)
			throw (Form::GradeTooLowException());
		else if (figure.getGrade() < 1)
			throw (Form::GradeTooHighException());
	}
	catch (std::exception &err) {
		return err.what();
	}
	this->isSigned = true;
	return ("");
}

std::string Form::getName() const{
	//std::cout << this->name;
	return (name);
}

int Form::getGradeToExecute() const{
	//std::cout << this->gradeToExecute;
	return (gradeToExecute);
}

int Form::getGradeToSign() const{
	//std::cout << this->gradeToSign;
	return (gradeToSign);
}

bool Form::getIsSigned() const{
	//std::cout << this->isSigned;
	return (isSigned);
}
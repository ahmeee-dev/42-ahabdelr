#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:

	// Canonical Form
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(Form &ToCopy);
		Form &operator =(const Form &rhs);

	// Methods
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		std::string beSigned(Bureaucrat figure);

	// Exceptions
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too low to sign!";
				}
		};

};

std::ostream& operator<<(std::ostream&os, const Form &rhs);


#endif
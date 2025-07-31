#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:

	// Canonical Form
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(AForm &ToCopy);
		AForm &operator =(const AForm &rhs);

	//Virtual
		virtual std::string execute(Bureaucrat const & executor) const = 0;
		virtual void specificOperation(std::string const &target) const = 0;
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
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too high to sign!";
				}
		};

};

std::ostream& operator<<(std::ostream&os, const AForm &rhs);


#endif
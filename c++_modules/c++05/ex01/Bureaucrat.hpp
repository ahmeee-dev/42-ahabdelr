#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	
	public:

	// Canonical Form
	Bureaucrat(std::string, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat &toCopy);
	Bureaucrat &operator =(const Bureaucrat &rhs);

	// Methods
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int amount);
	void decrementGrade(int amount);
	void signForm(Form toSign);

	// Exceptions
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too high!";
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too low!";
				}
		};
};

std::ostream& operator<<(std::ostream&os, const Bureaucrat &rhs);

#endif

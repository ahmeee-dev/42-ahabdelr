#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern() {};
		~Intern() {};
		Intern(Intern &ToCopy) { (void)ToCopy; };
		Intern &operator =(const Intern &rhs) { (void)rhs; return (*this); };

		AForm *createForm(std::string formName, std::string formTraget);
};

#endif
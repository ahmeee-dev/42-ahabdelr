#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	public:
		RobotomyRequestForm(std::string name, std::string target);
		std::string execute(Bureaucrat const & executor) const;
		void specificOperation(const std::string &target) const;

		class FormNotSignedException: public std::exception {
			public:
				const char* what() const throw() {
					return "Could not execute for the absend of a sign in";
				}
		};
};

#endif
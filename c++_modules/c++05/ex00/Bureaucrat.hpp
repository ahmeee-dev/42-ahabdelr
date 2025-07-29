#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		std::string name;
		int grade;
	
	public:

	//still to implement Orthodox canonical form functions

	// exceptions
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too high!";
				}
		};
		class GradeTooLowExeception: public std::exception {
			public:
				const char* what() const throw() {
					return "Grade too low!";
				}
		}
}

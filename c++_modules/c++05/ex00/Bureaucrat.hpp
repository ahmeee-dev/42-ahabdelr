#include <iostream>
#include <string>
#include <exception>

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
	void operator <<(const Bureaucrat &rhs);
	// Methods
	std::string getName();
	int getGrade();
	void incrementGrade(int amount);
	void decrementGrade(int amount);

	// Exceptions
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
		};
};

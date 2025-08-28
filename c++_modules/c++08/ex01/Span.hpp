#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <exception>

class OutOfRangeException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Unauthorized action: End of container reached");
		};
};

class NoElementsException : public std::exception {
	public: 
		virtual const char *what() const throw() {
			return ("Unauthorized action: At least one vector result empty");
		}
};

class Span {
	private:
		std::vector<int>  vec;
		int size;
		std::vector<int>::iterator it;

	public:
		Span(uint n);
		void addNumber(int n);
		int getSize();
		int getFullness();
		std::vector<int>::iterator getStart();
		int shortestSpan();
		int longestSpan();
};

#endif


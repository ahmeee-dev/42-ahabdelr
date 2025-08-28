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

class BadArgumentsException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Unauthorized action: Bad arguments");
		}
};

class RangTooBigException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Unauthorized action: Range inserted is too big for Container's availability");
		}
};

class NoElementsException : public std::exception {
	public: 
		virtual const char *what() const throw() {
			return ("Unauthorized action: Vector results empty");
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

		template <typename T>
		void addMultipleNumbers(typename T::iterator begin, typename T::iterator end) {
			if (begin > end) { throw BadArgumentsException(); };
			if (end - begin > this->getSize() - this->getFullness()) { throw RangTooBigException(); };
			for (int i = 0; i < end - begin; i++) {
				*this->it = *(begin + i);
				this->it++;
			}
		};

};

#endif


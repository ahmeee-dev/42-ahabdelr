#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <exception>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {

	private:
		typename std::stack<T> mutant;
		typename std::stack<T> *itStart;
		typename std::stack<T> *itEnd;
	
	public:
		MutantStack() {	this->mutant = std::stack<T>(); };
		template <typename A>
		MutantStack(A stackType) { this->mutant = std::stack<T>(stackType); };

		//typename std::stack<T> *getStart() { return this->mutant.begin(); };
		//typename std::stack<T> *getEnd() { return this->mutant.end(); }
};

#endif

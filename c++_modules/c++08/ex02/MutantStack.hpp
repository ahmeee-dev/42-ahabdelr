#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <exception>
#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {

	public: 
		typedef typename std::deque<T>::iterator iterator;
		MutantStack() {};

		typename std::deque<T>::iterator begin() { return (this->c.begin()); };
		typename std::deque<T>::iterator end() { return (this->c.end()); };
		void push(T elem) {this->c.push_back(elem); };
		void pop() { this->c.pop_back(); };
		T top() { return (this->c.back()); }; 
	//definisci classe iterator
};

#endif

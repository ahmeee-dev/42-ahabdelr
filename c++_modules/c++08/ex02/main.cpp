#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	MutantStack<int> mStack;

	mStack.push(1);
	mStack.push(2);
	mStack.push(3);
	mStack.push(4);
	mStack.push(5);
	mStack.push(11);
	mStack.push(22);
	mStack.push(33);
	mStack.push(44);
	mStack.push(55);

	std::cout << "Top(): " << mStack.top() << std::endl << "-----------" << std::endl;

	std::cout << "Elements: " << std::endl;
	for (MutantStack<int>::iterator itStart = mStack.begin(); itStart != mStack.end(); itStart++) {
		std::cout << *itStart << std::endl;
	}
	std::cout << "-----------" << std::endl << std::endl;

	mStack.pop();
	std::cout << "Last element popped" << std::endl << std::endl;

		std::cout << "Elements: " << std::endl;
	for (MutantStack<int>::iterator itStart = mStack.begin(); itStart != mStack.end(); itStart++) {
		std::cout << *itStart << std::endl;
	}
	std::cout << "-----------" << std::endl;


	std::stack<int> s(mStack);
}
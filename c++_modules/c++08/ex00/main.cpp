#include "easyfind.hpp"
#include <iostream>

int main( void ) {
	std::vector<int> mector(10);
	for (int i = 0; i < 10; i++) {
		mector[i] = i;
	}

	std::array<int, 10> marray;
	for (int i = 0; i < 10; i++) {
		marray[i] = i;
	}

	std::deque<int> meque;
	for (int i = 0; i < 10; i++) {
		meque.push_back(i);
	}
	try { std::cout << "Vector:" << *easyfind(mector, 1) << std::endl; } catch (ElementNotFoundException err) { std::cout << err.what() << std::endl; }
	try { std::cout << "Array:" << *easyfind(marray, 2) << std::endl; } catch (ElementNotFoundException err) { std::cout << err.what() << std::endl; }
	try { std::cout << "Deque:" << *easyfind(meque, 10) << std::endl; } catch (ElementNotFoundException err) { std::cout << err.what() << std::endl; }

}
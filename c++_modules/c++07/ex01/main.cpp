#include "iter.hpp"
#include <iostream>

void testFunction(int &num) {
	std::cout << num << std::endl;
	num = num * -1;
}
int main() {
	int *array = new int[14];
	for (int i = 0; i < 14; i++) {
		array[i] = i;
	}
	iteration(array, 14, testFunction);
	iteration(array, 14, testFunction);
	iteration(array, 14, testFunction);
}


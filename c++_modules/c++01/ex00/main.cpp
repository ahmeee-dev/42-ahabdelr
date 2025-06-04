#include "Zombie.hpp"

int main() {
	Zombie *heapZombie = newZombie("Zed");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Bob");

	return (0);
}
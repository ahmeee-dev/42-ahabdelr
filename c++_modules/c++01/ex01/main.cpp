#include "Zombie.hpp"

int main(){

	Zombie *horde = zombieHorde(15, "Gilberto");
	delete[] horde;
	return (0);
}
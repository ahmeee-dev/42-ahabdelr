#include <iostream>
#include "ClapTrap.hpp"

int main() {
    // Test costruttore con nome
    ClapTrap clap1("Robo-1");
    clap1.attack("Target Dummy");
    clap1.takeDamage(3);
    clap1.beRepaired(2);

    // Test costruttore di default
    ClapTrap clap2;
    clap2.attack("Target Dummy");

    // Test copy constructor
    ClapTrap clap3(clap1);
    clap3.attack("Copy Target");

    // Test operatore di assegnazione
    ClapTrap clap4;
    clap4 = clap2;
    clap4.attack("Assigned Target");

    // Test catena di danni/riparazioni
    ClapTrap clap5("Robo-2");
    clap5.takeDamage(8);
    clap5.beRepaired(5);
    clap5.takeDamage(10); // Dovrebbe "morire" qui
    clap5.beRepaired(5);  // Non dovrebbe funzionare

    return 0;
}
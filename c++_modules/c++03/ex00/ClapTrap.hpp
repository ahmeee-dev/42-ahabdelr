#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int hitPoints = 10;
		int energyPoints = 10;
		int attackDamage = 0;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &toCopy);
		~ClapTrap();
		ClapTrap &operator =(ClapTrap &rhs);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
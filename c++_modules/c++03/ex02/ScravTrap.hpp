#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap {
	public:
		ScravTrap();
		ScravTrap(std::string name);
		ScravTrap(ScravTrap &toCopy);
		~ScravTrap();
		ScravTrap &operator =(ScravTrap &rhs);
		void guardGate();
		void attack(const std::string &target);
};
#include "FragTrap.hpp"

class DiamondTrap : public ScravTrap, FragTrap {
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &toCopy);
		DiamondTrap &operator =(DiamondTrap &rhs);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();
};
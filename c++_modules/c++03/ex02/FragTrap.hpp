#include "ScravTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &toCopy);
		~FragTrap();
		FragTrap &operator =(FragTrap &rhs);

		void highFiveGuys(void);
};
#include "ICharacter.hpp"

class Character : virtual public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
		AMateria *dropped[10000];
		int droppedCount = 0;
	public:
		Character();
		~Character();
		Character &operator=(Character const &rhs);
		Character(Character &toCopy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
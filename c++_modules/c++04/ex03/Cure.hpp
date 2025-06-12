#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : virtual public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		~Cure();
		Cure &operator=(Cure const &rhs);
		Cure(Cure &toCopy);
		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
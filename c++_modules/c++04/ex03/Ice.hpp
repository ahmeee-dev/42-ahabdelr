#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : virtual public AMateria {
	public:
		Ice();
		~Ice();
		Ice &operator=(Ice const &rhs);
		Ice(Ice &toCopy);
		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
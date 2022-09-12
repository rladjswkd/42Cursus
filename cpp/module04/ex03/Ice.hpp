#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice &);
	~Ice(void);
	Ice	&operator=(Ice &);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
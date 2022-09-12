#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;
class AMateria
{
protected:
	std::string	type;
public:
	AMateria(void);
	AMateria(AMateria &);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria	&operator=(AMateria &);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif

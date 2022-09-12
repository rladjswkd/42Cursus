#include "AMateria.hpp"

AMateria::AMateria(void) : type("NoType"){}

AMateria::AMateria(AMateria &other) {
	*this = other;
}

AMateria::AMateria(std::string const & type) : type(type){}

AMateria::~AMateria(void){}

AMateria	&AMateria::operator=(AMateria &other){
	(void)other;
	// copying type doesn't make sense.
	return (*this);
}

std::string const & AMateria::getType() const{
	return (type);
}

void AMateria::use(ICharacter& target){
	std::cout << "It is invalid for " << target.getName() << " to use AMateria" << std::endl;
}
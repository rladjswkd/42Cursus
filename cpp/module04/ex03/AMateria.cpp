#include "AMateria.hpp"

// AMateria::AMateria(void) : type("NoType"){}

// AMateria::AMateria(AMateria &other) {
// 	*this = other;
// }

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << ""
}

AMateria::~AMateria(void){}

// AMateria	&AMateria::operator=(AMateria &other){
// 	// copying type doesn't make sense.
// 	return (*this);
// }

std::string const & AMateria::getType() const{
	return (type);
}

void AMateria::use(ICharacter& target){}
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::Ice(Ice &other) : AMateria(other){}

Ice::~Ice(void){}

Ice	&Ice::operator=(Ice &other){
	this->type = other.getType();
	return (*this);
}

AMateria* Ice::clone() const{
	return (new Ice());
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

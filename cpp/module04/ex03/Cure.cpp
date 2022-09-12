#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){}

Cure::Cure(Cure &other) : AMateria(other){}

Cure::~Cure(void){}

Cure	&Cure::operator=(Cure &other){
	this->type = other.getType();
	return (*this);
}

AMateria* Cure::clone() const{
	return (new Cure());
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

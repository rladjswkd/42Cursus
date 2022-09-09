#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type){
	setType(type);
}

const std::string	&Weapon::getType(void){
	return (type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}
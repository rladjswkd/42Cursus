#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weaponRef) : weapon(weaponRef){
	this->name = name;
	this->weapon = weaponRef;
}

void	HumanA::attack(void){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
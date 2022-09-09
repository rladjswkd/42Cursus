#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << name << " has been destroyed." << std::endl;
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
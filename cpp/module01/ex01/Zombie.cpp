#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void){}

Zombie::Zombie(std::string name){
    setName(name);
}

Zombie::~Zombie(void){
    std::cout << "Zombie " << name << " has been destroyed." << std::endl;
}

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
}
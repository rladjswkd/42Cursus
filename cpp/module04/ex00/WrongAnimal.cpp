#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other) : type("WrongAnimal"){
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &other){
	this->type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal has no generic sound." << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}

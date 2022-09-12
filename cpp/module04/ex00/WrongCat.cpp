#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	std::cout << "WrongCat default constructor" <<std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat &other){
	this->type = other.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "Wrong Meow" << std::endl;
}
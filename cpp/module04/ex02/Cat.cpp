#include "Cat.hpp"

Cat::Cat(void) : brain(new Brain()){
	std::cout << "Cat default constructor" <<std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat &other) : Animal(other){
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat(void){
	std::cout << "Cat destructor" << std::endl;
	delete (brain);
}

Cat	&Cat::operator=(Cat &other){
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}
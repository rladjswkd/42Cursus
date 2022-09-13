#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain()){
	std::cout << "Dog default constructor" <<std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog &other) : Animal(other), brain(new Brain(*(other.brain))){
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog::~Dog(void){
	std::cout << "Dog destructor" << std::endl;
	delete (brain);
}

Dog	&Dog::operator=(Dog &other){
	this->type = other.getType();
	*brain = *(other.brain);
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Woof" << std::endl;
}

void	Dog::printIdea(int index){
	std::cout << brain->getIdea(index) << std::endl;
}
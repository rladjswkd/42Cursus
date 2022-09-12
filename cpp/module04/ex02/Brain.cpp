#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(Brain &other){
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain::~Brain(void){
	std::cout << "Brain destructor" << std::endl;
}

Brain	&Brain::operator=(Brain &other){
	for (int i = 0; i < 100; i++)
		(this->ideas)[i] = (other.ideas)[i];
	return (*this);
}

std::string	Brain::getIdea(int index){
	return (ideas[index]);
}

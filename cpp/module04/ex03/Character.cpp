#include "Character.hpp"

Character::Character(void){
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(Character &other){
	*this = other;
}

Character::~Character(void){
	for (int i = 0; i < 4; i++)
		delete (inventory[i]);
}

Character	&Character::operator=(Character &){
	
}

std::string const & Character::getName() const{

}

void	Character::equip(AMateria* m){

}

void	Character::unequip(int idx){

}

void	Character::use(int idx, ICharacter& target){

}

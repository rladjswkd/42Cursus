#include "Character.hpp"

Character::Character(void){
	name = "Noname";
	for (int i = 0; i < 4; i++)
		slot[i] = 0;
}

Character::Character(Character &other){
	for (int i = 0; i < 4; i++)
		slot[i] = 0;
	*this = other;
}

Character::Character(std::string name){
	this->name = name;
	for (int i = 0; i < 4; i++)
		slot[i] = 0;
}

Character::~Character(void){
	for (int i = 0; i < 4; i++)
		delete (slot[i]); // delete in itself, checks null pointer.
}

Character	&Character::operator=(Character &other){
	if (this == &other)
		return (*this);
	name = other.getName();
	for (int i = 0; i < 4; i++){
		delete (slot[i]);
		slot[i] = 0;
		if (other.slot[i])
			slot[i] = (other.slot[i])->clone();
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (name);
}

void	Character::equip(AMateria* m){
	int	i = 0;
	while (i < 4 && slot[i])
		i++;
	if (i == 4)
		return ;
	else
		slot[i] = m;
}

void	Character::unequip(int idx){
	if (-1 < idx && idx < 4)
		slot[idx] = 0;	
}

void	Character::use(int idx, ICharacter& target){
	if (-1 < idx && idx < 5 && slot[idx])
		slot[idx]->use(target);
}

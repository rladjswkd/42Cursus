#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	className = "FragTrap";
	std::cout << this->className << " default constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other){
	className = "FragTrap";
	std::cout << this->className << " copy constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	className = "FragTrap";
	std::cout << this->className << " string constructor called." << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap &other){
	name = other.getName();
	hitPoint = other.getHitPoint();
	energyPoint = other.getEnergyPoint();
	attackDamage = other.getAttackDamage();
	className = other.getClassName();
	return (*this);
}

void	FragTrap::highFivesGuys(void){
	std::cout << "High Five!!!!" << std::endl;
}

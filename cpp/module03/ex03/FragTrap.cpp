#include "FragTrap.hpp"

FragTrap::FragTrap(void) : FTHitPoint(100), FTAttackDamage(30){
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	className = "FragTrap";
	std::cout << this->className << " default constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other), FTHitPoint(100), FTAttackDamage(30){
	className = "FragTrap";
	std::cout << this->className << " copy constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), FTHitPoint(100), FTAttackDamage(30){
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

int	FragTrap::getFTHitPoint(void){
	return (FTHitPoint);
}

int	FragTrap::getFTAttackDamage(void){
	return (FTAttackDamage);
}
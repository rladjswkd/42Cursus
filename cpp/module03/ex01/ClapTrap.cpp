#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
	static int	i = 0;

	std::cout << "Default constructor called" << std::endl;
	name = "Noname";
	name.append(1, i + 48);
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other){
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &rhs){
	name = rhs.getName();
	hitPoint = rhs.getHitPoint();
	energyPoint = rhs.getEnergyPoint();
	attackDamage = rhs.getAttackDamage();
	return (*this);
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "Name parameter constructor called" << std::endl;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	this->name = name;
}

void	ClapTrap::attack(const std::string& target){
	if (energyPoint > 0)
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
	else
		std::cout << "Zero Energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	hitPoint -= amount;
	energyPoint--;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (energyPoint > 0){
		std::cout << "ClapTrap " << name << " gets " << amount << " points back!" << std::endl;
		hitPoint += amount;
		energyPoint--;
	} else
		std::cout << "Zero Energy points!" << std::endl;
}

std::string	ClapTrap::getName(void){
	return (name);
}

int	ClapTrap::getHitPoint(void){
	return (hitPoint);
}

int	ClapTrap::getEnergyPoint(void){
	return (energyPoint);
}

int	ClapTrap::getAttackDamage(void){
	return (attackDamage);
}
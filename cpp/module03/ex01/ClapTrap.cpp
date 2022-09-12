/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:31 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:32 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
	name = "Noname";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	className = "ClapTrap";
	std::cout << this->className << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other){
	className = other.getClassName();
	std::cout << this->className << " copy constructor called" << std::endl;
	this->operator=(other);
}

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
	className = "ClapTrap";
	std::cout << this->className << " name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &rhs){
	name = rhs.getName();
	hitPoint = rhs.getHitPoint();
	energyPoint = rhs.getEnergyPoint();
	attackDamage = rhs.getAttackDamage();
	className = rhs.getClassName();
	return (*this);
}

void	ClapTrap::attack(const std::string& target){
	if (energyPoint > 0) {
		std::cout << this->className << " " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "Zero Energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << this->className << " " << name << " takes " << amount << " points of damage!" << std::endl;
	hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (energyPoint > 0){
		std::cout << this->className << " " << name << " gets " << amount << " points back!" << std::endl;
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

std::string	ClapTrap::getClassName(void){
	return (className);
}

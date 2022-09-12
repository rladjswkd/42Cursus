/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:23:02 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:23:03 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : STEnergyPoint(50){
	hitPoint = 100;
	energyPoint = STEnergyPoint;
	attackDamage = 20;
	className = "ScavTrap";
	std::cout << this->className << " default constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other), STEnergyPoint(50){
	className = "ScavTrap";
	std::cout << this->className << " copy constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), STEnergyPoint(50){
	this->name = name;
	hitPoint = 100;
	energyPoint = STEnergyPoint;
	attackDamage = 20;
	className = "ScavTrap";
	std::cout << this->className << " string constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &other){
	name = other.getName();
	hitPoint = other.getHitPoint();
	energyPoint = other.getEnergyPoint();
	attackDamage = other.getAttackDamage();
	className = other.getClassName();
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if (energyPoint > 0) {
		std::cout << "Different Message from Base class! "
		<< this->className << " " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
	else
		std::cout << "Zero Energy points!" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << this->className << " " << name << " is now in Gatekeeper mode." << std::endl;
}

int	ScavTrap::getSTEnergyPoint(void){
	return (STEnergyPoint);
}

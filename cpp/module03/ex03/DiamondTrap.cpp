/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:54 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:55 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Noname_clap_trap"){
	this->name = "Noname";
	hitPoint = FragTrap::getFTHitPoint(); //100;
	energyPoint = ScavTrap::getSTEnergyPoint(); //50;
	attackDamage = FragTrap::getFTAttackDamage(); //30;
	className = "DiamondTrap";
	std::cout << this->className << " default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other){
	*this = other;
	std::cout << this->className << " copy constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
	this->name = name;
	hitPoint = FragTrap::getFTHitPoint(); //100;
	energyPoint = ScavTrap::getSTEnergyPoint(); //50;
	attackDamage = FragTrap::getFTAttackDamage(); //30;
	className = "DiamondTrap";
	std::cout << this->className << " string constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &other){
	name = other.getPrivateName();
	hitPoint = other.getHitPoint();
	energyPoint = other.getEnergyPoint();
	attackDamage = other.getAttackDamage();
	className = other.getClassName();
	return (*this);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "DiamondTrap::name : " << this->name << ", ClapTrap::name : " << ClapTrap::name << std::endl;
}

std::string	DiamondTrap::getPrivateName(void){
	return (this->name);
}

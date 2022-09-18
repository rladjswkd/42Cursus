/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:26 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:27 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal"){
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(Animal &other) : type("Animal"){
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal::~Animal(void){
	std::cout << "Animal destructor" << std::endl;
}

Animal	&Animal::operator=(Animal &other){
	this->type = other.type;
	return (*this);
}

// void	Animal::makeSound(void) const{
// 	std::cout << "Animal is has no generic sound." << std::endl;
// }

std::string	Animal::getType(void) const{
	return (this->type);
}

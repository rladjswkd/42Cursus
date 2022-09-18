/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:43 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:45 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other) : type("WrongAnimal"){
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &other){
	this->type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal has no generic sound." << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}

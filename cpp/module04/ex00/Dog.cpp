/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:29 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
	std::cout << "Dog default constructor" <<std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog &other) : Animal(other){
	std::cout << "Dog copy constructor" << std::endl;
	*this = other;
}

Dog::~Dog(void){
	std::cout << "Dog destructor" << std::endl;
}

Dog	&Dog::operator=(Dog &other){
	this->type = other.getType();
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Woof" << std::endl;
}

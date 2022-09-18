/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:25 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
	std::cout << "Cat default constructor" <<std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat &other) : Animal(other){
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat(void){
	std::cout << "Cat destructor" << std::endl;
}

Cat	&Cat::operator=(Cat &other){
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}

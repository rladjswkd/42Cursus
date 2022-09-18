/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:46 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	std::cout << "WrongCat default constructor" <<std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat &other){
	this->type = other.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "Wrong Meow" << std::endl;
}

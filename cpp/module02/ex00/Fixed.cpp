/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:03 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 15:19:05 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed	&Fixed::operator=(const Fixed &rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed &rhs){
	std::cout << "Copy constructor called" << std::endl;
	operator=(rhs);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits(int const rawBits){
	std::cout << "getRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}

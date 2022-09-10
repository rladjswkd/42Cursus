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
#include <cmath>

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed	&Fixed::operator=(const Fixed &rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &rhs){
	std::cout << "Copy constructor called" << std::endl;
	operator=(rhs);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	return (rawBits);
}

void	Fixed::setRawBits(int const rawBits){
	this->rawBits = rawBits;
}

Fixed::Fixed(const int rhs){
	std::cout << "Int constructor called" << std::endl;
	rawBits = IntToFixed(rhs);
}

Fixed::Fixed(const float rhs){
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(rhs * (1 << fracBits));
}

float 	Fixed::toFloat(void) const{
	return (FixedToFloat(rawBits));
}

int 	Fixed::toInt(void) const{
	return (FixedToInt(rawBits));
}

std::ostream	&operator<<(std::ostream &oStream, const Fixed &fixed){
	oStream << fixed.toFloat();
	return (oStream);
}
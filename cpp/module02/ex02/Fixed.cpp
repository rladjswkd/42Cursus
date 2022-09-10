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
	rawBits = rhs << fracBits;
}

Fixed::Fixed(const float rhs){
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(rhs * (1 << fracBits));
}

float 	Fixed::toFloat(void) const{
	return ((float)rawBits / (1 << fracBits));
}

int 	Fixed::toInt(void) const{
	return (rawBits >> 8);
}

std::ostream	&operator<<(std::ostream &oStream, const Fixed &fixed){
	oStream << fixed.toFloat();
	return (oStream);
}

bool	Fixed::operator>(const Fixed &v) const{
	return (rawBits > v.getRawBits());
}

bool	Fixed::operator<(const Fixed &v) const{
	return (rawBits < v.getRawBits());
}

bool	Fixed::operator>=(const Fixed &v) const{
	return (rawBits >= v.getRawBits());
}

bool	Fixed::operator<=(const Fixed &v) const{
	return (rawBits <= v.getRawBits());
}

bool	Fixed::operator==(const Fixed &v) const{
	return (rawBits == v.getRawBits());
}

bool	Fixed::operator!=(const Fixed &v) const{
	return (rawBits != v.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &v){
	return (Fixed(this->toFloat() + v.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &v){
	return (Fixed(this->toFloat() - v.toFloat()));
}

Fixed	Fixed::operator-(void){
	return (Fixed(-rawBits));
}

Fixed	Fixed::operator*(const Fixed &v){
	return (Fixed(this->toFloat() * v.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &v){
	return (Fixed(this->toFloat() / v.toFloat()));
}

Fixed	&Fixed::operator++(void){
	rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int i){
	Fixed	ret;

	(void)i;
	ret.setRawBits(rawBits++);
	return (ret);
}

Fixed	&Fixed::operator--(void){
	rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int i){
	Fixed	ret;

	(void)i;
	ret.setRawBits(rawBits--);
	return (ret);
}

Fixed	&Fixed::min(Fixed &v1, Fixed &v2){
	if (v1 > v2)
		return (v2);
	return (v1);
}

const Fixed	&Fixed::min(const Fixed &v1, const Fixed &v2){
	if (v1 > v2)
		return (v2);
	return (v1);
}

Fixed	&Fixed::max(Fixed &v1, Fixed &v2){
	if (v1 < v2)
		return (v2);
	return (v1);
}

const Fixed	&Fixed::max(const Fixed &v1, const Fixed &v2){
	if (v1 < v2)
		return (v2);
	return (v1);
}
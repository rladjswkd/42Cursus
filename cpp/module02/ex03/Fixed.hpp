/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:06 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 15:19:07 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <fstream>
class Fixed
{
private:
	int					rawBits;
	static const int	fracBits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);

	~Fixed();

	int 	getRawBits(void) const;
	void	setRawBits(int const);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;

	Fixed	&operator=(const Fixed &);

	bool	operator>(const Fixed &) const;
	bool	operator<(const Fixed &) const;
	bool	operator>=(const Fixed &) const;
	bool	operator<=(const Fixed &) const;
	bool	operator==(const Fixed &) const;
	bool	operator!=(const Fixed &) const;

	Fixed	operator+(const Fixed &);
	Fixed	operator-(const Fixed &);
	Fixed	operator-(void);
	Fixed	operator*(const Fixed &);
	Fixed	operator/(const Fixed &);

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	
	static Fixed		&min(Fixed &, Fixed &);
	static const Fixed	&min(const Fixed &, const Fixed &);
	static Fixed		&max(Fixed &, Fixed &);
	static const Fixed	&max(const Fixed &, const Fixed &);
};

std::ostream	&operator<<(std::ostream &, const Fixed &);
#endif

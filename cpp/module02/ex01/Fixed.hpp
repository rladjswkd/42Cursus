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
	Fixed	&operator=(const Fixed &);
	~Fixed();
	int 	getRawBits(void) const;
	void	setRawBits(int const);
	
	Fixed(const int);
	Fixed(const float);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &, const Fixed &);
#endif

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
#define SCALE 8
#define FloatToFixed(x)	((x) * (float)(1 << SCALE))
#define FixedToFloat(x)	((float)(x) / (float)(1 << SCALE))
#define IntToFixed(x)	((x) << SCALE)
#define FixedToInt(x)	((x) >> SCALE)
class Fixed
{
private:
	int					rawBits;
	static const int	fracBits = SCALE;
public:
	Fixed(void);
	Fixed(const Fixed &);
	~Fixed(void);
	Fixed	&operator=(const Fixed &);
	int 	getRawBits(void) const;
	void	setRawBits(int const);
	
	Fixed(const int);
	Fixed(const float);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &, const Fixed &);
#endif

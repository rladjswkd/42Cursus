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
class Fixed
{
private:
	int					rawBits; // real number
	static const int	fracBits = 8; // the number of continuous bits including least significant bits to represent fractional part
public:
	Fixed(void);
	Fixed(Fixed &);
	Fixed	&operator=(const Fixed &);
	~Fixed();
	int 	getRawBits(void) const;
	void	setRawBits(int const);
};
#endif

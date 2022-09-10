/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:09 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 15:19:13 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const b( Fixed( 5.05f ) / Fixed( 0 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed	c(10.5f);
	Fixed	d(5.3f);
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << -c << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;

	Fixed	e(10.5f);
	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c >= e) << std::endl;
	std::cout << (c <= e) << std::endl;
	std::cout << (c == e) << std::endl;
	std::cout << (c != d) << std::endl;
	return 0;
}

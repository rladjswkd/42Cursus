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

#include "Point.hpp"
#include <iostream>
bool bsp(Point const a, Point const b, Point const c, Point const point);
int main(void) {
	Point const	a = Point(0.2345f, 0.465f);
	Point const	b = Point(19.564f, 0.1134f);
	Point const	c = Point(10.6844f, 30.3434f);
	Point const	point = Point(10.6844f, 29.3434f);

	if (bsp(a, b, c, point))
		std::cout << "this point is in the triangle." << std::endl;
	else
		std::cout << "this point is NOT in the triangle." << std::endl;
	return 0;
}

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
// fractional bits가 8개 밖에 없고, float에 비해 precision이 떨어지므로, 정밀한 수에 대해 수행하면 결과적으로 true여도 false를 반환할 수 있다.
int main(void) {
	Point const	a = Point(0, 0);
	Point const	b = Point(20, 0);
	Point const	c = Point(10, 30);
	Point const	point = Point(10, 31);

	if (bsp(a, b, c, point))
		std::cout << "this point is in the triangle." << std::endl;
	else
		std::cout << "this point is NOT in the triangle." << std::endl;
	return 0;
}

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	area = Point::getArea(a, b, c);
	Fixed	bcp = Point::getArea(point, b, c);
	Fixed	acp = Point::getArea(a, point, c);
	Fixed	abp = Point::getArea(a, b, point);
	Fixed	sum = abp + acp + bcp;

	if (area == sum)
	 	return (true);
	return (false);
}
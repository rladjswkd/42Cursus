#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	area = Point::getArea(a, b, c);
	Fixed	bcp = Point::getArea(point, b, c);
	Fixed	acp = Point::getArea(a, point, c);
	Fixed	abp = Point::getArea(a, b, point);

	if (area == abp + acp + bcp)
	 	return (true);
	return (false);
}
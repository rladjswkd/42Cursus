#include "Point.hpp"

/* ************************************************************************** */
/*                                area method                                 */
/* ************************************************************************** */
Fixed	getArea(const Point p1, const Point p2, const Point p3){
	Fixed	denominator(2.0f);
	Fixed	area(((p1.getX() * (p2.getY() - p3.getY()))
				+ (p2.getX() * (p3.getY() - p1.getY()))
				+ (p3.getX() * (p1.getY() - p2.getY()))) / denominator);

	if (area < 0)
		area = -area;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	area = getArea(a, b, c);
	Fixed	bcp = getArea(point, b, c);
	Fixed	acp = getArea(a, point, c);
	Fixed	abp = getArea(a, b, point);
	Fixed	sum = abp + acp + bcp;

	if (area == sum)
	 	return (true);
	return (false);
}

/* ************************************************************************** */
/*                               vector method                                */
/* ************************************************************************** */
// bool	bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	w1Nominator((a.getX() * (c.getY() - a.getY())) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY()));
// 	Fixed	w1Denominator((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));
// 	Fixed	w1(w1Nominator / w1Denominator);
// 	Fixed	w2Nominator(point.getY() - a.getY() - w1 * (b.getY() - a.getY()));
// 	Fixed	w2Denominator(c.getY() - a.getY());
// 	Fixed	w2(w2Nominator / w2Denominator);
// 	bool	ret;

// 	if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
// 		ret = true;
// 	else
// 		ret = false;
// 	return (ret);
// }
#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point(void);
	Point(const Point &);
	Point(const float, const float);
	~Point(void);
	Point	&operator=(const Point &);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};
#endif
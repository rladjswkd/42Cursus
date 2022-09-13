#include "Point.hpp"

Point::Point(void) : x(0), y(0){}

Point::Point(const Point &point){
	operator=(point);
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point(void){}

Point	&Point::operator=(const Point &rhs){
	const_cast<Fixed&>(x) = rhs.getX();
	const_cast<Fixed&>(y) = rhs.getY();
	return (*this);
}

Fixed	Point::getX(void) const{
	return (x);
}

Fixed	Point::getY(void) const{
	return (y);
}

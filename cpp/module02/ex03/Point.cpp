#include "Point.hpp"

Point::Point(void){
	x.setRawBits(0);
	y.setRawBits(0);
}

Point::Point(const Point &point){
	operator=(point);
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point(void){}

Point	&Point::operator=(const Point &rhs){
	this->x.setRawBits(rhs.getX().getRawBits());
	this->y.setRawBits(rhs.getY().getRawBits());
	return (*this);
}

Fixed	Point::getX(void) const{
	return (x);
}

Fixed	Point::getY(void) const{
	return (y);
}

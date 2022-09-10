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

Fixed	Point::getArea(const Point p1, const Point p2, const Point p3){
	Fixed	area = ((p1.getX() * (p2.getY() - p3.getY()))
				+ (p2.getX() * (p3.getY() - p1.getY()))
				+ (p3.getX() * (p1.getY() - p2.getY()))) / 2.0f;

	if (area < 0)
		area = -area;
	return (area);
}


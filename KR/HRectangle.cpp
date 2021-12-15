#include "HRectangle.h"

HRectangle::HRectangle(const Point& apexA, const double side1_len, const double side2_len)
	: HTetragon{apexA, Point{apexA.x(), apexA.y() + side1_len},
		Point{apexA.x() + side2_len, apexA.y() + side1_len},
		Point{apexA.x() + side2_len, apexA.y()}}
{}

const Point& HRectangle::apexA() const
{
	return HTetragon::apexA();
}

const Point& HRectangle::apexB() const
{
	return HTetragon::apexB();
}

 const Point& HRectangle::apexC() const
{
	 return HTetragon::apexC();
}

const Point& HRectangle::apexD() const
{
	return HTetragon::apexD();
}

 Point& HRectangle::setA()
{
	
}

 Point& HRectangle::setB()
{
	
}

Point& HRectangle::setC()
{
	
}

Point& HRectangle::setD()
{
	
}


#include "Point.h"

using namespace std;

int Point::_freeID = 0;

Point::Point(double x, double y) :
	_x(x), _y(y), _pointID(_freeID)
{
	_freeID += 1;

#ifndef NDEBUG
	cout << "Constructing " << *this << " id = " << _pointID << endl;
#endif
}

Point::Point(const Point& p) :
	_x(p.x()), _y(p.y()), _pointID(_freeID)
{
	_freeID += 1;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "Destructing " << *this << " id = " << _pointID << endl;
#endif
}

double& Point::x()
{
	return _x;
}


double& Point::y()
{
	return _y;
}


const double& Point::x() const
{
	return _x;
}


const double& Point::y() const
{
	return _y;
}

int Point::getID() const
{
	return _pointID;
}

int Point::amount()
{
	return _freeID;
}

Point& Point::operator=(const Point& p)
{
	_x = p.x();
	_y = p.y();
	return *this;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "Point(" << p.x() << ", " << p.y() << ")";
	return os;
}

Point operator+(const Point& u, const Point& v)
{
	double x = u.x() + v.x();
	double y = u.y() + v.y();
	return Point(x, y);
}

Point& Point::operator+=(const Point& p)
{
	x() = x() + p.x();
	y() = y() + p.y();

	return *this;
}

bool operator==(const Point& u, const Point& v)
{
	return (u.x() == v.x() && u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}
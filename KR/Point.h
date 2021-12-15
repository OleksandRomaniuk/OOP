#pragma once

#include <iostream>


class Point
{
private:
	static int _freeID;
	const int _pointID;
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);
	Point& operator+=(const Point&);
	double& x();
	double& y();
	const double& x() const;
	const double& y()const;
	int getID() const;
	static int amount();
	
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend Point operator+(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);
};



#pragma once
#include "Point.h"
#include "Segment.h"

class HTetragon
{
protected:
	Point _apexA;
	Point _apexB;
	Point _apexC;
	Point _apexD;

public:
	HTetragon(const Point& apexA, const Point& apexB, const Point& apexC, const Point& apexD);
	
	virtual const Point& apexA() const = 0;
	virtual const Point& apexB() const = 0;
	virtual const Point& apexC() const = 0;
	virtual const Point& apexD() const = 0;

	virtual Point& setA() = 0;
	virtual Point& setB() = 0;
	virtual Point& setC() = 0;
	virtual Point& setD() = 0;
};

#pragma once
#include <iostream>
#include "Point.h"

class Segment
{
private:
	static int _call;
	static int freeID;
	int myId;
	Point _a, _b;
public:
	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);
	Segment(const Point& start, const Point& end);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment&);
	const Point& start() const;
	const Point& end() const;
	double length() const;
	double distance(const Point&) const;
	int getID() const { return myId; }
	static int epilog();
};

std::ostream& operator<<(std::ostream&, const Segment&);

#pragma once
#include "Point.h"
#include "Segment.h"
#include "HTetragon.h"

class HRectangle: public HTetragon
{
public:
	HRectangle(const Point& apexA, const double side1_len, const double side2_len);

	virtual const Point& apexA() const override;
	virtual const Point& apexB() const override;
	virtual const Point& apexC() const override;
	virtual const Point& apexD() const override;

	virtual Point& setA() override;
	virtual Point& setB() override;
	virtual Point& setC() override;
	virtual Point& setD() override; 
};


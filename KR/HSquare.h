#pragma once
#include "Point.h"
#include "Segment.h"
#include "HTetragon.h"

class HSquare: public HTetragon
{
public:
	HSquare(const Point& apexA, const double side_len);
};

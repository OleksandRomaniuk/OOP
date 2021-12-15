#include "HSquare.h"
#include <cassert>

HSquare::HSquare(const Point& apexA, const double side_len)
	: HTetragon{apexA, Point{apexA.x(), apexA.y() + side_len},
		Point{apexA.x() + side_len, apexA.y() + side_len},
		Point{apexA.x() + side_len, apexA.y()}}
{}


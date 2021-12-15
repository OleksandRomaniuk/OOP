#include "HTetragon.h"

HTetragon::HTetragon(const Point& apexA, const Point& apexB, const Point& apexC, const Point& apexD)
	: _apexA{apexA}, _apexB{apexB}, _apexC{apexC}, _apexD{apexD}
{}

const Point& HTetragon::apexA() const
{
	return _apexA;
}

const Point& HTetragon::apexB() const
{
	return _apexB;
}

const Point& HTetragon::apexC() const
{
	return _apexC;
}

const Point& HTetragon::apexD() const
{
	return _apexD;
}


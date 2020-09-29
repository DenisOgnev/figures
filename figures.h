#pragma once
#include <cmath>

class figure
{
protected:
	double a, b, x0, y0;

public:
	virtual double getArea() = 0;
};

class circle : virtual figure
{
public:
	circle() {};
	circle(double _a, double _x0, double _y0) 
	{ 
		if (_a < 0)
		{
			throw "Radius can't be negative";
		}
		a = _a;
		b = _a;
		x0 = _x0;
		y0 = _y0;
	};
	virtual double getArea() { return acos(-1) * a * b; };
};

class ellipse : virtual figure
{
public:
	ellipse() {};
	ellipse(double _a, double _b, double _x0, double _y0) 
	{
		if (_a < 0 || _b < 0)
		{
			throw "Radius can't be negative";
		}
		a = _a;
		b = _b;
		x0 = _x0;
		y0 = _y0;
	};
	virtual double getArea() { return acos(-1) * a * b; };
};

struct Comparator
{
	bool operator()(ellipse* e1, ellipse* e2) { return e1->getArea() < e2->getArea(); }
};


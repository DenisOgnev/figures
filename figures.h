#pragma once
#include <cmath>

class figure
{
public:
	virtual double getArea() = 0;
};

class circle : public figure
{
private:
	double a;
public:
	circle(double _a) 
	{ 
		if (_a < 0)
			throw "Radius can't be negative";
		a = _a;
	};
	double getArea() override { return acos(-1) * a * a; };
};

class ellipse : public figure
{
private:
	double a, b;
public:
	ellipse(double _a, double _b) 
	{
		if (_a < 0 || _b < 0)
			throw "Radius can't be negative";
		a = _a;
		b = _b;
	};
	double getArea() override { return acos(-1) * a * b; };
};

struct Comparator
{
	bool operator()(const std::shared_ptr<figure>& f1, const std::shared_ptr<figure>& f2) {return f1->getArea() < f2->getArea(); }
};


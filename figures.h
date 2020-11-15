#pragma once
#include <iostream>
#include <cmath>

class figure;
class circle;
class ellipse;

class visitor
{
public:
	void visit(std::shared_ptr<figure> c)
	{
		std::cout << "Visited figure" << std::endl;
	};

	void visit(std::shared_ptr<circle> c)
	{
		std::cout << "Visited circle" << std::endl;
	};

	void visit(std::shared_ptr<ellipse> e)
	{
		std::cout << "Visited ellipse" << std::endl;
	};
};

class figure
{
public:
	virtual double getArea() = 0;
	virtual void accept(visitor* v) = 0;
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
	void accept(visitor* v) override
	{
		std::shared_ptr<circle> ptr(this);
		v->visit(ptr);
	};
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
	void accept(visitor* v) override
	{
		std::shared_ptr<ellipse> ptr(this);
		v->visit(ptr);
	};
};

struct Comparator
{
	bool operator()(const std::shared_ptr<figure>& f1, const std::shared_ptr<figure>& f2) {return f1->getArea() < f2->getArea(); }
};


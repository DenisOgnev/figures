#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "figures.h"
#include <typeinfo>

using namespace std;

int main()
{
	vector<shared_ptr<figure>> v;
	double a, b, sumOfAreas = 0;
	int size = 10;
	srand(time(NULL));

	int choose;

	for (int i = 0; i < size; i++)
	{
		choose = rand() % 2 + 1;
		a = (double)(rand()) / RAND_MAX * 20;
		b = (double)(rand()) / RAND_MAX * 20;
		if (choose == 1)
		{
			circle* c = new circle(a);
			shared_ptr<circle> ptr(c);
			v.push_back(ptr);
		}
		else
		{
			ellipse* e = new ellipse(a, b);
			shared_ptr<ellipse> ptr(e);
			v.push_back(ptr);
		}
	}

	sort(v.begin(), v.end(), Comparator());

	for (int i = 0; i < size; i++)
	{
		cout << v[i]->getArea() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		sumOfAreas += v[i]->getArea();
	}

	cout << "\nSum of areas: " << sumOfAreas << endl;

	return 0;
}
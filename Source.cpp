#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "figures.h"

using namespace std;

bool compare_ellipses(ellipse* e1, ellipse* e2) { return e1->getArea() < e2->getArea(); };

int main()
{
	double a, b, x0, y0, sumOfAreas = 0;
	int size = 10;
	vector<ellipse*> v;
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		a = (double)(rand()) / RAND_MAX * 20;
		b = (double)(rand()) / RAND_MAX * 20;
		y0 = (double)(rand()) / RAND_MAX * 20;
		x0 = (double)(rand()) / RAND_MAX * 20;
		//ellipse *e = new ellipse(a, b, x0, y0);
		v.push_back(new ellipse(a, b, x0, y0));
	}

	sort(v.begin(), v.end(), compare_ellipses);

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
#include <cmath>
#include <string>
#include <iostream>
#include "geometry.h"
using namespace std;

enum colors
{
	GREEN = 1,
	YELLOW = 2,
	PURPLE = 4,
	RED = 8
};

	void Figure::setR(double value)
	{
		radius = value;
	}

	void Figure::setA(double value)
	{
		a = value;
	}

	void Figure::setB(double value)
	{
		b = value;
	}

	void Figure::circle()
	{
		area = atan(1) * 4 * radius;
		a = radius * 2;
		a_rect = a + 0.1;
		b_rect = a + 0.1;
		color |= GREEN;
	}

	void Figure::square()
	{
		area = a * a;
		a_rect = a + 0.1;
		b_rect = a + 0.1;
		color |= YELLOW;
	}

	void Figure::triangle()
	{
		area = a * a * sqrt(3) / 4;
		a_rect = a + 0.1;
		b_rect = 0.3 * a + 0.1;
		color |= PURPLE;
	}

	void Figure::rectangle()
	{
		area = a * b;
		a_rect = a + 0.1;
		b_rect = b + 0.1;
		color |= RED;
	}

	void Figure::show()
	{
		if (color & GREEN)
		{
			cout << "Color: green" << endl;
		}
		if (color & YELLOW)
		{
			cout << "Color: yellow" << endl;
		}
		if (color & PURPLE)
		{
			cout << "Color: purple" << endl;
		}
		if (color & RED)
		{
			cout << "Color: red" << endl;
		}
		cout << "Square: " << area << endl;
		cout << "Side of rectangle: " << a_rect << " & " << b_rect << endl;
		color = NULL;
	}

	Figure* Figure::origin(string command)
	{
		double A = 0;
		double B = 0;
		double R = 0;
		Figure* figure = new Figure;

		if (command == "circle")
		{
			cout << "Input radius: ";
			cin >> R;
			figure->setR(R);
			figure->circle();
		}
		if (command == "square")
		{
			cout << "Input length side: ";
			cin >> A;
			figure->setA(A);
			figure->square();
		}
		if (command == "triangle")
		{
			cout << "Input length side: ";
			cin >> A;
			figure->setA(A);
			figure->triangle();
		}
		if (command == "rectangle")
		{
			cout << "Input length side 1: ";
			cin >> A;
			cout << "Input length side 2: ";
			cin >> B;
			figure->setA(A);
			figure->setB(B);
			figure->rectangle();
		}
		figure->show();
		return nullptr;
	}

	int Figure::end(int q)
	{
		q = -1;
		return q;
	}
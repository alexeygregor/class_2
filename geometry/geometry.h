#pragma once
#include <string>
using namespace std;

enum colors;

class Figure
{
	int color = 0;
	double a = 0;
	double b = 0;
	double a_rect = 0;
	double b_rect = 0;
	double radius = 0;
	double area = 0;

public:

	void setA(double value);

	void setB(double value);

	void setR(double value);

	void circle();

	void square();

	void triangle();

	void rectangle();

	void show();

	static Figure* origin(string command);

	int end(int q);
};



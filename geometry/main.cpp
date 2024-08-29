#include <cmath>
#include <string>
#include <iostream>
#include "geometry.h"
using namespace std;


int main()
{
	int q = 0;
	string command;
	Figure* figure = new Figure();
	
	while (q != -1)
	{
		cout << "\nEnter command: ";
		cin >> command;

		if (command == "end")
		{
			q = figure->end(q);
		}
		else
		{
			figure->origin(command);
		}
	}
	delete figure;
}
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "company.h"
using namespace std;


int main()
{
	int teams = 0, value = 0;
	string name, valid_teams, valid_value;

	cout << "Enter your name: ";
	cin >> name;

	int i = 3;
	while (i > 0)
	{
		cout << "Input teams count: ";
		cin >> valid_teams;
		try
		{
			teams = stoi(valid_teams);
		}
		catch (exception)
		{
			--i;
			cerr << "Input error.Try again" << endl;
			continue;
		}
		i = 0;
	}
	assert(stoi(valid_teams));

	Manager* manager = new Manager(teams);
	manager->setDirector(name);
	origin(*manager);

	cout << "\nInput administrator name: ";
	cin >> name;
	manager->setManager(name);
	db(*manager);
	manager->allWorkers();

	while (value != -1)
	{
		int i = 3;
		while (i > 0)
		{
			cout << "\nDirector " << manager->getDirector() << " input team : ";
			cin >> valid_value;
			try
			{
				value = stoi(valid_value);
			}
			catch (exception)
			{
				--i;
				cerr << "Input error.Try again" << endl;
				continue;
			}
			i = 0;
		}
		assert(stoi(valid_value));
		--value;
		getStatus(*manager, value);
		if (manager->getWorker().size() == manager->getTasks().size())
		{
			cout << "\nEmployment: " << endl;
			manager->employment(value);
			break;
		}
	}
	delete manager;
}

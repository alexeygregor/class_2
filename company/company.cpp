#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "company.h"
using namespace std;


	void Workers::setPersons(int value)
	{
		persons = value;
	}

	int Workers::getPersons()
	{
		return persons;
	}

	void Workers::setPerson(int value)
	{
		person = value;
	}

	int Workers::getPerson()
	{
		return person;
	}

	void Workers::setName(string N)
	{
		name = N;
	}

	string Workers::getName()
	{
		return name;
	}

	void Workers::setStatus(string S)
	{
		status = S;
	}

	string Workers::getStatus()
	{
		return status;
	}


	void Manager::setDirector(string name)
	{
		director_name = name;
	}

	string Manager::getDirector()
	{
		return director_name;
	}

	void Manager::setManager(string name)
	{
		manager_name = name;
	}

	string Manager::getManager()
	{
		return manager_name;
	}

	void Manager::initWorker(Workers& workers)
	{
		worker.push_back(workers);
	}

	vector<Workers> Manager::getWorker()
	{
		return worker;
	}

	void Manager::outWorker(Workers& workers, int count)
	{
		workers = getWorker().at(count);
	}

	void Manager::initTasks(Workers& workers)
	{
		tasks.push_back(workers);
	}

	vector<Workers> Manager::getTasks()
	{
		return tasks;
	}

	void Manager::outTasks(Workers& workers, int cnt)
	{
		workers = getTasks().at(cnt);
	}

	int Manager::getCount()
	{
		return count;
	}

	Workers* Manager::getWorkers(int index)
	{
		if (index < 0) return nullptr;
		if (index >= count) return nullptr;
		return workers[index];
	}

	void Manager::allWorkers()
	{
		int k = 0;
		for (int i = 0; i < getCount(); ++i)
		{
			Workers& workers = *getWorkers(i);
			cout << "\nTeam " << i + 1 << ":" << endl;
			for (int j = k; j < workers.getPersons() + k; ++j)
			{
				outWorker(workers, j);
				cout << j + 1 << " " << workers.getPerson() + 1 << " " << workers.getName() << endl;
			}
			k += workers.getPersons();
		}
		cout << "\nAll workers: " << getWorker().size() << endl;
	}

	int Manager::checkName(Workers& worker, string name, int value)
	{
		for (int y = 0; y < getTasks().size(); ++y)
		{
			outTasks(worker, y);
			if (name == worker.getName())
			{
				return false;
			}
		}
		return true;
	}

	void Manager::employment(int value)
	{
		Workers& workers = *getWorkers(value);
		for (int i = 0; i < getTasks().size(); ++i)
		{
			outTasks(workers, i);
			cout << workers.getPerson() + 1 << " " << workers.getName() << " " << workers.getStatus() << endl;
		}
	}

	Manager::Manager(int inCount): count(inCount)
	{
		assert(inCount >= 0);
		workers = new Workers* [count];
		for (int i = 0; i < count; ++i)
		{
			workers[i] = new Workers();
		}
	}


Manager* origin(Manager& manager)
{
	int persons = 0;
	string valid_persons;
	cout << "\n_____Director: " << manager.getDirector() << "\n\n";
	int i = 0, j = 3;
	while (i < manager.getCount() && j > 0)
	{
		bool ch = true;
		cout << "Input " << i + 1 << " team membership: ";
		cin >> valid_persons;
		try
		{
			persons = stoi(valid_persons);
		}
		catch (exception)
		{
			--j;
			cerr << "Input error. Try again" << endl;
			ch = false;
		}
		if (ch)
		{
			manager.getWorkers(i)->setPersons(persons);
			valid_persons = to_string(persons);
			++i;
		}
	}
	assert(stoi(valid_persons));
	return nullptr;
}

Manager* db(Manager& manager)
{
	string name;
	cout << "\n_____Manager: " << manager.getManager() << "\n\n";
	for (int i = 0; i < manager.getCount(); ++i)
	{
		Workers& workers = *manager.getWorkers(i);
		cout << "Team " << i + 1 << ": " << endl;
		for (int j = 0; j < workers.getPersons(); ++j)
		{
			cout << "Input " << j + 1 << " membership: ";
			cin >> name;
			workers.setPerson(i);
			workers.setName(name);
			manager.initWorker(workers);
		}
	}
	return nullptr;
}


Manager* distribute(Manager& manager, vector<string>status, int value)
{
	string name;
	int k = 0, t = 0;
	for (int i = 0; i < manager.getCount(); ++i)
	{
		Workers& workers = *manager.getWorkers(i);
		for (int j = k; j < workers.getPersons() + k; ++j)
		{
			manager.outWorker(workers, j);
			if (workers.getPerson() == value && t < status.size())
			{
				name = workers.getName();
				if (manager.checkName(workers, name, value) || manager.getTasks().size() == 0)
				{
					manager.outWorker(workers, j);
					workers.setStatus(status[t]);
					++t;
					manager.initTasks(workers);
					manager.outTasks(workers, manager.getTasks().size() - 1);
					cout << j << " "
						<< workers.getPerson() << " " << workers.getName() << " " << workers.getStatus() << endl;
				}
			}
		}
		k += workers.getPersons();
	}
	cout << "\nIn work: " << manager.getTasks().size() << endl;
	return nullptr;
}


Manager* getStatus(Manager& manager, int value)
{
	int cnt = 0, k = 0, id = 06;
	string task, tasks;
	vector<string>status;
	int tasksCount = rand() % (manager.getWorker().size() + 1);
	if (tasksCount == 0)
	{
		tasksCount += id;
	}
	cout << "\nTasks: " << tasksCount << endl;

	for (int i = 0; i < manager.getCount(); ++i)
	{
		Workers* vec1 = manager.getWorkers(i);
		for (int j = k; j < vec1->getPersons() + k; ++j)
		{
			manager.outWorker(*vec1, j);
			if (vec1->getPerson() == value)
			{
				cnt += 1;
			}
		}
		k += vec1->getPersons();
	}

	k = 0;
	for (int i = 0; i < manager.getTasks().size(); ++i)
	{
		Workers* vec2 = manager.getWorkers(i);
		manager.outTasks(*vec2, i);
		if (vec2->getPerson() == value)
		{
			cnt -= 1;
		}
		else
		{
			break;
		}
	}

	if (cnt)
	{
		int count = tasksCount;
		for (int i = 1; i <= cnt; ++i)
		{
			if (count == 0)
			{
				break;
			}
			if (i % 3 == 0)
			{
				task = "C";
			}
			else if (i % 2 == 0)
			{
				task = "B";
			}
			else
			{
				task = "A";
			}
			status.push_back(task);
			--count;
		}

		int n = 0;
		for (int i = cnt + 1; i <= tasksCount; ++i)
		{
			if (i % 3 == 0)
			{
				task = "C";
			}
			else if (i % 2 == 0)
			{
				task = "B";
			}
			else
			{
				task = "A";
			}
			status[n] += task;
			++n;
			if (n == cnt)
			{
				n = 0;
			}
		}
		distribute(manager, status, value);
	}
	return nullptr;
}
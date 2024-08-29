#pragma once
#include <string>
#include <vector>
using namespace std;


class Workers
{
	int person = 0;
	int persons = 0;
	string name, status = "FREE";

public:

	void setPersons(int value);

	int getPersons();

	void setPerson(int value);

	int getPerson();

	void setName(string N);

	string getName();

	void setStatus(string S);

	string getStatus();
};


class Manager
{
	int count = 0, teams = 0;
	string director_name, manager_name;
	Workers** workers = nullptr;
	vector<Workers>worker;
	vector<Workers>tasks;

public:

	void setDirector(string name);

	string getDirector();

	void setManager(string name);

	string getManager();

	void initWorker(Workers& workers);

	vector<Workers>getWorker();

	void outWorker(Workers& workers, int count);

	void initTasks(Workers& workers);

	vector<Workers>getTasks();

	void outTasks(Workers& workers, int cnt);

	int getCount();

	Workers* getWorkers(int index);

	void allWorkers();

	int checkName(Workers& worker, string name, int value);

	void employment(int value);

	Manager(int inCount);
};


Manager* origin(Manager& manager);

Manager* db(Manager& manager);

Manager* distribute(Manager& manager, vector<string>status, int value);

Manager* getStatus(Manager& manager, int value);
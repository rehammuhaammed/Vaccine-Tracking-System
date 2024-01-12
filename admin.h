#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "User.h"
using namespace std;
class admin
{
public:
	typedef User::vaccineperson vaccineperson;
public:
	User u;
	vector<vaccineperson>v;
	void basicStatistics(queue<vaccineperson>record);
	void waitingList(queue<vaccineperson>record);
	void ViewByNumOfDoses(queue<vaccineperson>record);
	void ViewByAge(queue<vaccineperson>record);
	void viewTheRecords(queue<vaccineperson>record);
	queue<vaccineperson> deleteAllRecords(queue<vaccineperson>record);
	queue<vaccineperson> deleteByID(queue<vaccineperson>record);
};


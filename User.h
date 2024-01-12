#pragma once
#include <string>
#include<iostream>
#include<queue>
using namespace std;
class User
{
public:
	struct login {
		long long nationalID;
		string password;
	};
	struct vaccineperson {

		string fullName;
		long long nationalID;
		string password;
		string Gender;
		int age;
		string governate;
		string vaccineStatus;
		int vaccine_times;
	};
	
public:
	queue<vaccineperson> records;
	vector<vaccineperson>v;
	queue <login> q;
	login u;
	long long national_id;
	vaccineperson person;
	/*User(login u, vaccineperson person) {
		this->u = u;
		this->person = person;
	}*/


public:
	//bool is_empty(std::fstream& pFile);
	void Add_personal_record();
	void Display_Vaccine_List();
	void registration();
	void user_login();
	void admin_login();
	void admin_menu();
	int mainmenu();
	bool check_Id(long long id);
	void menustart();
	void user_menu();
	void add_record_readFiles();
	void add_record_writeFiles();
	long long solve(string myString);
	void edit();
	void deleteFromqueue();

};
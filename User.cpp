#include "User.h"
#include "admin.h"
#include<iostream>
#include<fstream>
#include <vector>
#include<string>
#include<queue>
#include <sstream>

using namespace std;
//Function to convert number to string (used in files function)
long long User::solve(string myString) {
	long long x;
	stringstream ss(myString);
	ss >> x;
	return x;
}
//function to write the pre saved data in struct varible
//bool User::is_empty(fstream& pFile)
//{
//	return pFile.peek() == std::fstream::traits_type::eof();
//}
void User::add_record_writeFiles() {

	fstream myfile;
	myfile.open("PersonalVaccine.txt", ios::in);
	/*myfile.seekg(0, ios::end);
	 int length;
	if (myfile.tellg() == 0) {
		cout << "999999999999" << endl;
		myfile.close();
	}
	else */if (myfile.is_open()) {
		string line;
		while (!myfile.eof()) {
			//cout << "44444444444" << endl;
			bool is_repeated = false;
			vaccineperson record;
			login user;
			getline(myfile, line);
			record.fullName = line;
			getline(myfile, line);
			record.nationalID = solve(line);
			//cout << line << endl;
			user.nationalID = record.nationalID;
			getline(myfile, line);
			record.password = line;
			user.password = record.password;
			getline(myfile, line);
			record.Gender = line;
			getline(myfile, line);
			record.age = solve(line);
			getline(myfile, line);
			record.governate = line;
			getline(myfile, line);
			record.vaccineStatus = line;
			getline(myfile, line);
			record.vaccine_times = solve(line);
			
			records.push(record);
			queue<login>temp = q;
			while (!temp.empty()) {
				if (temp.front().nationalID == user.nationalID)
				{
					is_repeated = true;
					break;
				}
				temp.pop();
			}
			if (is_repeated == false)
			{
				q.push(user);
			}


		}
		//cout << records.front().age << endl;
	}
	myfile.close();
}
//function to save data after finishing the program
void User::add_record_readFiles() {
	queue<vaccineperson> temp = records;
	fstream myfile;
	myfile.open("PersonalVaccine.txt", ios::out);
	if (myfile.is_open()) {
		while (!temp.empty()) {
			myfile << temp.front().fullName << endl;
			myfile << temp.front().nationalID << endl;
			myfile << temp.front().password << endl;
			myfile << temp.front().Gender << endl;
			myfile << temp.front().age << endl;
			myfile << temp.front().governate << endl;
			myfile << temp.front().vaccineStatus << endl;
			myfile << temp.front().vaccine_times << endl;
			temp.pop();
		}
		myfile.close();
	}
}
void User::Add_personal_record()
{
	int doses;
	vaccineperson newvaccineperson;
	char choice = 'y';
	while (choice == 'y' || choice == 'Y') {
		cout << "############################### ADD PESONAL INFORMATION VACCINE ####################################" << endl;

		cout << "Enter Data:\n\n" << endl;


		cout << "Enter FullName: ";
		cin >> newvaccineperson.fullName;
		//getline(cin, newvaccineperson.fullName);
		//cin.ignore();

		while (true) {
			cout << "\nEnter National ID *(13 digit): ";

			// read the input from the user
			cin >> newvaccineperson.nationalID;

			// check if the input is a number and exactly 13 digits long
			if (cin.good() && to_string(newvaccineperson.nationalID).length() == 13) {
				break; // exit the loop
			}
			else {
				cout << "Error: National ID must be a 13-digit number." << endl;
				cin.clear(); // clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line
			}
		}
		cout << "\nEnter Password: ";
		cin >> newvaccineperson.password;


		cout << "\nEnter Gender: ";
		cin >> newvaccineperson.Gender;

		cout << "\nEnter age: ";
		cin >> newvaccineperson.age;
		cout << "\nEnter Governate: ";
		cin >> newvaccineperson.governate;


		do {
			cout << " \nvaccinated (V) or applying for vaccination (A) :";
			cin >> newvaccineperson.vaccineStatus;
			if (newvaccineperson.vaccineStatus == "V" || newvaccineperson.vaccineStatus == "v") {
				while (true) {
					cout << "\nHow many doeses received ? : (1 or 2) :";
					cin >> doses;
					if (doses == 1 || doses == 2) {
						newvaccineperson.vaccine_times = doses;
						records.push(newvaccineperson);
						break;
					}
					else
						cout << "WRONG ANSWER" << endl;
				}

			}
			else if ((newvaccineperson.vaccineStatus == "A" || newvaccineperson.vaccineStatus == "a")) {
				newvaccineperson.vaccine_times = 0;
				records.push(newvaccineperson);
			}else
				cout << "WRONG ANSWER" << endl;
			
		} while (newvaccineperson.vaccineStatus != "v" && newvaccineperson.vaccineStatus != "V" && newvaccineperson.vaccineStatus != "a" && newvaccineperson.vaccineStatus != "A");
		cout << "\n\n Add another record ? (y/n) :";
		cin >> choice;
		system("cls");
	}
}
void User::Display_Vaccine_List()
{
	vector<vaccineperson> users;
	queue< vaccineperson>temp = records;
	while (!temp.empty()) {
		users.push_back(temp.front());
		temp.pop();
	}
	int index = -1;
	cout << "                          *********************************************   \n";
	cout << "                                           USER RECORDS                       \n";
	cout << "                          *********************************************      \n";
	for (int i = 0; i < users.size(); i++) {
		if (users[i].nationalID == national_id) {
			index = i;
			cout << "\n\tFull Name      : " << users[index].fullName << endl;
			cout << "\n\tNational ID    : " << users[index].nationalID << endl;
			cout << "\n\tGender         : " << users[index].Gender << endl;
			cout << "\n\tAge            : " << users[index].age << endl;
			cout << "\n\tGovernorate    : " << users[index].governate << endl;
			if (users[index].vaccineStatus == "V" || users[index].vaccineStatus == "v") {
				cout << "\n\tVaccine Status : Vaccinated" << endl;
			}
			else if (users[index].vaccineStatus == "A" || users[index].vaccineStatus == "a") {
				cout << "\n\tVaccine Status : Applying for vaccine" << endl;
			}
			cout << "\n\tVaccine times  : " << users[index].vaccine_times << endl;
			cout << "\n\t\t--------------------------------------------------------------" << endl;
		}
	}
	system("pause");
	system("cls");

}
void User::registration()
{
	system("cls");


	cout << "                          ********************************************************    \n";
	cout << "                                              Registration                      \n";
	cout << "                          *********************************************************      \n";




	bool input = false;

	while (true) {
		cout << "Enter National ID *(13 digit): ";

		// read the input from the user
		cin >> u.nationalID;

		// check if the input is a number and exactly 13 digits long
		if (cin.good() && to_string(u.nationalID).length() == 13) {
			break; // exit the loop
		}
		else {
			cout << "Error: National ID must be a 13-digit number." << endl;
			cin.clear(); // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line
		}
	}







	while (check_Id(u.nationalID) == true)
	{
		cout << "\t the id is exit\n";
		while (true) {
			cout << "Enter National ID *(13 digit): ";

			// read the input from the user
			cin >> u.nationalID;

			// check if the input is a number and exactly 13 digits long
			if (cin.good() && to_string(u.nationalID).length() == 13) {
				break; // exit the loop
			}
			else {
				cout << "Error: National ID must be a 13-digit number." << endl;
				cin.clear(); // clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line
			}
		}


	}

	string pswd, pswd2;
	do
	{ // Password validation
		cout << "\n Set your password: ";
		cin >> pswd;
		cout << " Confirm password: ";
		cin >> pswd2;
		if (pswd != pswd2)
			cout << "Password does not match! Set up your password again!";
	} while (pswd != pswd2);
	u.password = pswd;


	cout << "                          --------------------------------------------------   \n";
	cout << "                                      Registration  successfully                  \n";
	cout << "                          --------------------------------------------------    \n";

	q.push(u);
	// file **
	system("pause"); // wait for user to press enter
	system("cls"); // clear screen
	mainmenu();

}
void User::user_login()
{
	system("cls");

	cout << "                          ************************************************\n\n";
	cout << "                                             LOGIN SYSTEM                    \n\n";
	cout << "                          ************************************************\n\n";


	//long long national_id;

	bool valid_input = false;

	while (true) {
		cout << "Enter National ID *(13 digit): ";

		// read the input from the user
		cin >> national_id;

		// check if the input is a number and exactly 13 digits long
		if (cin.good() && to_string(national_id).length() == 13) {
			break; // exit the loop
		}
		else {
			cout << "Error: National ID must be a 13-digit number." << endl;
			cin.clear(); // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line
		}
	}
	// Search for the user's ID in the queue
	bool found = false;
	login u;
	queue<login> temp = q;

	while (!temp.empty()) {
		u = temp.front();
		temp.pop();
		if (u.nationalID == national_id)
		{
			found = true;
			break;
		}
	}


	if (!found) {
		cout << "\nSorry, your ID is not registered." << endl;
		system("pause");
		system("cls");
		mainmenu();
	}
	else {


		string pass;

		cout << "\n Enter your password :";
		cin >> pass;

		if (u.password == pass) {

			cout << "\n\tLogged in successfully." << endl;
			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			user_menu();

		}
		else {
			cout << "\nWrong password! Please try again." << endl;
			system("pause");
			system("cls");
			mainmenu();
		}


	}

	return;


}
void User::admin_login()
{
	system("cls");

	cout << "                          ************************************************\n\n";
	cout << "                                              LOGIN Admin                    \n\n";
	cout << "                          ************************************************\n\n";




	string mail;
	bool is_login = false;
	while (true) {
		cout << "\nEnter Admin mail: ";
		cin >> mail;


		if (mail == "admin") {
			break; // exit the loop
		}
		else {
			cout << "\n invaild Admin mail  \n";
			cin.clear(); // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line
		}
	}
	string pas;
	bool tru_pass = false;
	while (true) {
		cout << "\n Enter your password :";
		cin >> pas;

		if (pas == "admin") {

			cout << "\n\tLogged in successfully." << endl;
			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			admin_menu();
			break;

		}
		else {
			cout << "\n Wrong password! Please try again." << endl;
			cin.clear(); // clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input line

		}
	}

}
void User::admin_menu()
{
	int choice;
	bool valid_input = false;
	while (!valid_input) {
		cout << "                          *********************************************   \n";
		cout << "                                           ADMIN MENU                       \n";
		cout << "                          *********************************************      \n";
		cout << "1.View All Record\n";
		cout << "2.Delete Record By Id\n";
		cout << "3.Delete ALL Records \n";
		cout << "4.View statistics\n";
		cout << "5.View All Record In Waiting List\n";
		cout << "6.view by number of doses\n";
		cout << "7.ViewByAge\n";
		cout << "8.Logout\n";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: 
		{
			system("cls");
			// View all or persons  a specific person by id
			admin m;
			m.viewTheRecords(records); 
		}
			break;
		case 2:
		{
			system("cls");
			admin m;
			records = m.deleteByID(records);
		}
			break;
		case 3:
		{	system("cls");
			admin m;
			records = m.deleteAllRecords(records);
		}
			break;
		case 4:
		{
			//View statistics();
			system("cls");
			admin m;
			m.basicStatistics(records);

		}
		break;
		case 5:
		{
			system("cls");
			admin m;
			m.waitingList(records);
		}
		//View All Record In Waiting List();
		break;



		case 8:
			cout << "                                   -----------------------------------   \n";
			cout << "                                                Signed out                 \n";
			cout << "                                   -----------------------------------    \n";

			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			valid_input = true;
			mainmenu();
			break;
		case 6:
			{
			system("cls");
				admin m;
				m.ViewByNumOfDoses(records);
			}
				break;
		case 7:
		{
			system("cls");
			admin m;
			m.ViewByAge(records);
		}
		break;


		default:
			cout << "\n\t\tPlease enter a valid choice." << endl;
			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			admin_menu();
		}
	}

}
int User::mainmenu()
{
	char choice;
	menustart();

	cin >> choice;

	switch (choice) {
	case '1':
		registration();

		break;
	case '2':
		user_login();
		break;
	case '3':
		admin_login();
		break;

	case 'e':
		cout << "\n\t\tThank you for using App." << endl;
		break;
	default:
		cout << "\n\t\tThe choice you entered was not valid, please enter a valid option." << endl;
		break;

	}


	return 0;
}
bool User::check_Id(long long id)
{

	queue<login> temp = q; // create a temporary queue to iterate through all users

	while (!temp.empty()) {
		login u = temp.front();
		temp.pop();
		if (u.nationalID == id) {
			//cout << u.nationalID << " " << id << endl;
			return true;
		}
	}
	return false;
}
void User::menustart()
{
	cout << "                          ******************************************************************    \n";
	cout << "                                       WELCOME  TO VACCINE TRACHING SYSTEM                          \n";
	cout << "                          *******************************************************************      \n";

	cout << "\n\t----------------------" << endl;
	cout << "\n\t MAIN MENU" << endl;
	cout << "\n\t1. Register for vaccine." << endl;
	cout << "\n\t2. Login as user." << endl;
	cout << "\n\t3. Login as Admin." << endl;
	cout << "\n\tEnter 'e' to exit." << endl;
	cout << "\n\t----------------------" << endl;
	cout << "\n\t Enter choice :";
}
void User::user_menu()
{
	int choice;
	bool valid_input = false;
	while (!valid_input) {
		cout << "                          *********************************************   \n";
		cout << "                                           USER MENU                       \n";
		cout << "                          *********************************************      \n";
		cout << "1.Display all records\n";
		cout << "2.Add Data Vaccine\n";
		cout << "3.Edit\n";
		cout << "4.delete\n";
		cout << "5.Logout\n";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Display_Vaccine_List();
			//display records
			break;
		case 2:
			system("cls");
			Add_personal_record();
			//ADD();
			break;
		case 3:
			system("cls");
			edit();
			//edituser();
			break;
		case 4:
			system("cls");
			deleteFromqueue();
			//deleteuser();
			break;

		case 5:
			cout << "                                   -----------------------------------   \n";
			cout << "                                                Signed out                 \n";
			cout << "                                   -----------------------------------    \n";

			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			valid_input = true;
			mainmenu();
			break;
		default:
			cout << "\n\t\tPlease enter a valid choice." << endl;
			system("pause"); // wait for user to press enter
			system("cls"); // clear screen
			user_menu();
		}





	}
}
void User::edit() {
	vector<vaccineperson> users;
	while (!records.empty()) {
		users.push_back(records.front());
		records.pop();
	}
	int index = -1;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].nationalID == national_id) {
			index = i;
			break;
		}
	}
	int choice;
	do {
		cout << "                          ************************************************\n\n";
		cout << "                                             Edit Page                    \n\n";
		cout << "                          ************************************************\n\n";
		cout << "\n\nWhat field do you want to edit?" << endl;
		cout << "\t1. Name\n" << endl;
		cout << "\t2. Password\n" << endl;
		cout << "\t3. Gender\n" << endl;
		cout << "\t4. Age\n" << endl;
		cout << "\t5. Governorate\n" << endl;
		cout << "\t6. vaccine status\n" << endl;
		cout << "\t0. Exit\n" << endl;
		cout << " \tEnter your choice :";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			cout << "\n\t\t\t\t\tEnter your new name: ";
			cin >> users[index].fullName;
			cout << "\t\t\t\t**********Name updated successfully.**********" << endl;
			system("pause");
			system("cls");
		}
		break;
		case 2:
		{
			cout << "\n\t\t\t\t\tEnter your new password: ";
			cin >> users[index].password;
			cout << "\t\t\t\t**********Password updated successfully.**********" << endl;
			system("pause");
			system("cls");
		}
		break;
		case 3:
			cout << "\n\t\t\t\t\tEnter your new gender (M/F): ";
			cin >> users[index].Gender;
			cout << "\t\t\t\t**********Gender updated successfully.**********" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "\n\t\t\t\t\tEnter your new age: ";
			cin >> users[index].age;
			cout << "\t\t\t\t**********Age updated successfully.**********" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "\n\t\t\t\t\tEnter your new governorate: ";
			cin >> users[index].governate;
			cout << "\t\t\t\t**********Governorate updated successfully.**********" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			char answer;
			cout << "\n\t\t\t\t\tHave you been vaccinated? (Y/N): ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y') {
				users[index].vaccineStatus = "v";
				users[index].vaccine_times = 2;
				cout << "\t\t\t\t**********Vaccination status updated successfully.**********" << endl;
				system("pause");
				system("cls");

			}
			else {
				users[index].vaccineStatus = "a";
				cout << "\n\t\t\t\t\tHow many doses have you received? :";
				cin >> users[index].vaccine_times;
				cout << "\t\t\t\t**********Vaccination status updated successfully**********." << endl;
				system("pause");
				system("cls");
			}

			break;
		case 0:
			cout << "\t\t\t\t**********Exiting...**********" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "\t\t\t\t**********Invalid choice.**********" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (choice != 0);
	for (auto user : users) {
		records.push(user);
	}
}
void User::deleteFromqueue()
{
	queue<vaccineperson> q1;
	long long id;
	bool found = true;
	cout << "Enter your id that you want to delete" << endl;
	cin >> id;

	while (!records.empty()) {

		if (id == records.front().nationalID) {
			records.pop();
			continue;
		}
		q1.push(records.front());
		records.pop();
	}
	while (!records.empty()) {
		records.pop();
	}
	records = q1;
	if (found == false) {
		cout << "User id not found" << endl;
	}
	else {
		cout << "\t\t\t\t * *********Record deleted successfully.**********" << endl;
	}
	system("pause");
	system("cls");


}
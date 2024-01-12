#include "admin.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
typedef User::vaccineperson vaccineperson;
using namespace std;


void admin::waitingList(queue<vaccineperson>record) {
    queue<vaccineperson>temp = record;
    vector<vaccineperson>v;
    while (!temp.empty()) {

        v.push_back(temp.front());
        temp.pop();
    }
    cout << "                          ******************************************************************    \n";
    cout << "                                          WELCOME  TO Waiting List Records                         \n";
    cout << "                          *******************************************************************      \n";
    for (auto element : v) {
        if (element.vaccineStatus == "A" || element.vaccineStatus == "a") {
            cout << endl;
            cout << "\n\n\n\tName            :" << element.fullName << endl;
            cout << "\n\tID              :" << element.nationalID << endl;
            cout << "\n\tGender          :" << element.Gender << endl;
            cout << "\n\tAge             :" << element.age << endl;
            cout << "\n\tGovernorate     :" << element.governate << endl;
            cout << "\n\tNumber of doses :" << element.vaccine_times << endl;
            cout << "\n\tWaiting list    :yes" << endl;
            cout << "\n----------------------------------------------------" << endl;
        }
    }
    system("pause");
    system("cls");
}
void admin::basicStatistics(queue<vaccineperson>record) {
    queue<vaccineperson>temp = record;
    vector<vaccineperson>v;
    while (!temp.empty()) {
        v.push_back(temp.front());
        temp.pop();
    }
    cout << "                          ******************************************************************    \n";
    cout << "                                       WELCOME  TO VACCINE TRACKING  REPORT                          \n";
    cout << "                          *******************************************************************      \n";
    float maleCounter = 0, femaleCounter = 0, oneDoseCounter = 0, twoDoseCounter = 0;
    for (auto element : v)
    {
        if (element.Gender == "m" || element.Gender == "M" || element.Gender == "Male" || element.Gender == "male" || element.Gender == "MALE")
            maleCounter++;
        else if (element.Gender == "f" || element.Gender == "F" || element.Gender == "Female" || element.Gender == "female" || element.Gender == "FEMALE")
            femaleCounter++;

        if (element.vaccine_times == 1)
            oneDoseCounter++;
        else if (element.vaccine_times == 2)
            twoDoseCounter++;

    }
    int femalePercentage = (femaleCounter / v.size()) * 100;
    int malePercentage = (maleCounter / v.size()) * 100;
    int oneDosePercentage = (oneDoseCounter / v.size()) * 100;
    int twoDosePercentage = (twoDoseCounter / v.size()) * 100;
    cout << "\n\n\n\tthe percentage of Females   :" << femalePercentage << "%" << endl;
    cout << "\n\tthe percentage of Males     :" << malePercentage << "%" << endl;
    cout << "\n\tthe percentage of One Dose  :" << oneDosePercentage << "%" << endl;
    cout << "\n\tthe percentage of Two Doses :" << twoDosePercentage << "%" << endl;
    system("pause");
    system("cls");

}
void admin::ViewByNumOfDoses(queue<vaccineperson>record)
{
    queue<vaccineperson>temp = record;
    vector<vaccineperson>v;
    while (!temp.empty())
    {
        v.push_back(temp.front());
        temp.pop();
    }
    cout << "                          ******************************************************************    \n";
    cout << "                                       WELCOME  TO  Number  of  Doses  REPORT                          \n";
    cout << "                          *******************************************************************      \n";
    cout << "Enter number of doses \n";
    int NumOfDoses;
    cin >> NumOfDoses;
    for (auto element : v) {
        if (element.vaccine_times == NumOfDoses)
        {
            cout << endl;
            cout << "\n\n\n\tName            :" << element.fullName << endl;
            cout << "\n\tID              :" << element.nationalID << endl;
            cout << "\n\tGender          :" << element.Gender << endl;
            cout << "\n\tAge             :" << element.age << endl;
            cout << "\n\tGovernorate     :" << element.governate << endl;
            cout << "\n\tNumber of doses :" << element.vaccine_times << endl;
            if (element.vaccineStatus == "v" || element.vaccineStatus == "V")
            {
                cout << "\n\t User is vaccinated" << endl;
            }
            else if (element.vaccineStatus == "a" || element.vaccineStatus == "A")
            {
                cout << "\n\t User is applying to vaccine" << endl;
            }
            cout << "\n----------------------------------------------------" << endl;
        }

    }
    system("pause");
    system("cls");
}
void admin::ViewByAge(queue<vaccineperson>record)
{
    queue<vaccineperson>temp = record;
    vector<vaccineperson>v;
    while (!temp.empty())
    {
        v.push_back(temp.front());
        temp.pop();
    }
    cout << "                          ******************************************************************    \n";
    cout << "                                       WELCOME  TO  ORDERED VACCINATED  REPORT                          \n";
    cout << "                          *******************************************************************      \n";
    vector <vaccineperson> s;
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].age > v[j].age)
            {
                vaccineperson temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    v.erase(v.begin());

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].vaccineStatus == "V" || v[i].vaccineStatus == "v") {
            cout << endl;
            cout << "\n\n\n\tName            :" << v[i].fullName << endl;
            cout << "\n\tID              :" << v[i].nationalID << endl;
            cout << "\n\tGender          :" << v[i].Gender << endl;
            cout << "\n\tAge             :" << v[i].age << endl;
            cout << "\n\tGovernorate     :" << v[i].governate << endl;
            cout << "\n\tNumber of doses :" << v[i].vaccine_times << endl;
            cout << "\n----------------------------------------------------" << endl;

        }
    }
    system("pause");
    system("cls");
}
queue<vaccineperson> admin::deleteAllRecords(queue<vaccineperson>record)
{
    while (!record.empty()) {
        record.pop();
    }
    cout << "All records have been deleted" << endl;

    system("pause");
    system("cls");
    return record;
}
queue<vaccineperson> admin::deleteByID(queue<vaccineperson>record)
{
    long long id;
    cout << "Please Enter the ID you want to DELETE : ";
    cin >> id;
    vector<vaccineperson> v;
    queue<vaccineperson> r = record;

    // Read data from file into vector
    while (!r.empty()) {
        v.push_back(r.front());
        r.pop();
    }
    // Find and delete the record
    auto it = find_if(v.begin(), v.end(), [&](const vaccineperson& p) {
        return p.nationalID == id;
        });

    if (it != v.end())
    {
        v.erase(it);
        cout << "Record with ID " << id << " has been deleted" << endl;
    }
    else
    {
        cout << "Record with ID " << id << " not found" << endl;
    }
    // Rewrite the updated vector to the file
    v.pop_back();
    for (const auto& value : v) {
        r.push(value);
    }
    


    system("pause");
    system("cls");
    return r;
}
void admin::viewTheRecords(queue<vaccineperson>record)
{
    queue<vaccineperson>temp = record;
    vector<vaccineperson> r;
    vaccineperson person;
    while (!temp.empty()) {
        r.push_back(temp.front());
        temp.pop();
    }

    if (r.empty())
    {
        cout << "No records found" << endl;
        return;
    }

    int choice;
    cout << "Select an option:" << endl;
    cout << "1. View all records" << endl;
    cout << "2. View record by ID" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Viewing all records:" << endl;

        for (const auto& person : r)
        {
            cout << "Full Name: " << person.fullName << endl;
            cout << "National ID: " << person.nationalID << endl;
            cout << "Gender: " << person.Gender << endl;
            cout << "Age: " << person.age << endl;
            cout << "Governate: " << person.governate << endl;
            cout << "Vaccine Status: " << person.vaccineStatus << endl;
            cout << "Vaccine Times: " << person.vaccine_times << endl;
            cout << "\n----------------------------------------------------" << endl;
            cout << endl;
        }
    }
    else if (choice == 2)
    {
        long long  id;
        cout << "Enter the ID of the person: ";
        cin >> id;

        auto it = find_if(r.begin(), r.end(), [&](const vaccineperson& p) {
            return p.nationalID == id;
            });

        if (it != r.end())
        {
            cout << "Viewing user with ID " << id << ":" << endl;
            const vaccineperson& person = *it;
            cout << "Full Name: " << person.fullName << endl;
            cout << "National ID: " << person.nationalID << endl;
            cout << "Gender: " << person.Gender << endl;
            cout << "Age: " << person.age << endl;
            cout << "Governate: " << person.governate << endl;
            cout << "Vaccine Status: " << person.vaccineStatus << endl;
            cout << "Vaccine Times: " << person.vaccine_times << endl;
            cout << "\n----------------------------------------------------" << endl;
        }
        else
        {
            cout << "Person with ID " << id << " not found" << endl;
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
    system("pause");
    system("cls");

}



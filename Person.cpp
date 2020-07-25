#include "Person.h"
#include"mDate.h"
#include"Name.h"

Person::Person()
{
	pr_age = 0;
	pr_Nid = 0;
}

Person::Person(int age, int Nid, int day, int month, int year, const char* fname, const char* lname)
{
	pr_DOB.SetDate(day, month, year);
	pr_pName.Set_person_name(fname, lname);
	pr_age = age;
	pr_Nid = Nid;
}

Person::Person(Person& obj_in)
{
	pr_DOB.CopyDate(obj_in.pr_DOB);
	pr_pName.CopyName(obj_in.pr_pName);
	pr_age = obj_in.pr_age;
	pr_Nid = obj_in.pr_Nid;
}

void Person::SetAge(int age)
{
	pr_age = age;
}

void Person::SetNid(int Nid)  
{
	pr_Nid = Nid;
}

void Person::SetDOB(int day, int month, int year)
{
	pr_DOB.SetDate(day, month, year);
}

void Person::SetpName(const char* fname, const char* lname)
{
	pr_pName.Set_person_name(fname, lname);
}

void Person::AddData()
{
	char* temp_array1;
	char* temp_array2;
	temp_array1 = new char[20];
	temp_array2 = new char[20];
	cout << "	Enter First Name : ";
	cin.getline(temp_array1, 20);
	cout << "	Enter Last Name :  ";
	cin.getline(temp_array2, 20);
	pr_pName.Set_person_name(temp_array1, temp_array2);
	int day, month, year;
	cout << "	Enter Date of Birth (Day Month Yera) : " << endl;
	cout << "	Day :   ";
	cin >> day;
	cout << "	Month : ";
	cin >> month;
	cout << "	Year :  ";
	cin >> year;
	pr_DOB.SetDate(day, month, year);

	cout << "	Enter National ID # : ";
	cin >> pr_Nid;
	cout << "	Enter Age : ";
	cin >> pr_age;

	delete[]temp_array1;
	delete[]temp_array2;
}

void Person::AddData(int age, int Nid, int day, int month, int year, const char* fname, const char* lname)
{
	pr_DOB.SetDate(day, month, year);
	pr_pName.Set_person_name(fname, lname);
	pr_age = age;
	pr_Nid = Nid;
}

int Person::GetAge()
{
	return pr_age;
}

int Person::GetNid()
{
	return pr_Nid;
}

mDate Person::GetDOB()
{
	return pr_DOB;
}

Name Person::GetName()
{
	return pr_pName;
}

ostream& operator<<(ostream& out, Person& obj_in)
{
	out << "	Name                    : ";
	out << obj_in.pr_pName;
	out << "	Date of Birth           : ";
	out << obj_in.pr_DOB << endl;
	out << "	Age                     : " << obj_in.pr_age << endl;
	out << "	National ID #           : " << obj_in.pr_Nid << endl;
	return out;
}

#include "Patient.h"
#include<iostream>

using namespace std;
Patient::Patient()
{
	pr_pID = 0;
	pr_record_history = nullptr;
	pr_record_no = 0;
}


Patient::Patient(int pID, int age, int nID, int day, int month, int year, const char* fname, const char* lname) :Person(age, nID, day, month, year, fname, lname)
{
	pr_pID = pID;
	pr_record_history = nullptr;
	pr_record_no = 0;
}

Patient::Patient(int pID)
{
	pr_record_history = nullptr;
	pr_record_no = 0;
	pr_pID = pID;
}

Patient::Patient(Patient& obj_in) :Person(obj_in)
{
	pr_pID = obj_in.pr_pID;
	pr_record_no = obj_in.pr_record_no;
	if (obj_in.pr_record_history != nullptr)
	{
		pr_record_history = new pRecord*[obj_in.pr_record_no];
		for (int i = 0; i < pr_record_no; i++)
		{
			pr_record_history[i] = new pRecord(obj_in.pr_record_history[i][0]);
		}
	}
	else
	{
		pr_record_history = nullptr;
	}
}

void Patient::SetpID(int pID)
{
	pr_pID = pID;
}

//void Patient::AddRecord()
//{
//	char* temp_array = new char[20];
//	cout << "	Enter Disease Name : ";
//	cin.getline(temp_array, 20);
//	int ASSignDoc = 0;
//	cout << "	Enter Assigned Doctor ID : ";
//	cin >> ASSignDoc;
//	int day = 0, month = 0, year = 0;
//	cout << "	Enter Visiting Date (Day Month Year) : " << endl;
//	cout << "	Day : ";
//	cin >> day;
//	cout << "	Month : ";
//	cin >> month;
//	cout << "	Year : ";
//	cin >> year;
//	int hour = 0, min = 0, sec = 0;
//	cout << "	Enter Visiting Time(Hours Minutes Seconds) : " << endl;
//	cout << "	Hours : ";
//	cin >> hour;
//	cout << "	Minutes : ";
//	cin >> min;
//	cout << "	Seconds : ";
//	cin >> sec;
//	float Total_Charge = 0, Paid_Charge = 0;
//	cout << "	Enter Total Charges : ";
//	cin >> Total_Charge;
//	cout << "	Enter Paid Charges";
//	cin >> Paid_Charge;
//
//	if (pr_record_history == nullptr)
//	{
//		pr_record_history = new pRecord*;
//		pr_record_history[pr_record_no] = new pRecord(temp_array, ASSignDoc, Total_Charge, Paid_Charge, day, month, year, hour, min, sec);
//		pr_record_no++;
//		cin.ignore();
//
//	}
//	else
//	{
//		pRecord** Temp_History;
//		Temp_History = new pRecord * [pr_record_no];
//
//		for (int i = 0; i < pr_record_no; i++)
//		{
//			Temp_History[i] = pr_record_history[i];
//		}
//
//		delete[]pr_record_history;
//		pr_record_history = nullptr;
//
//		pr_record_history = new pRecord * [pr_record_no + 1];
//		for (int i = 0; i < pr_record_no; i++)
//		{
//			pr_record_history[i] = Temp_History[i];
//		}
//		pr_record_history[pr_record_no] = new pRecord(temp_array, ASSignDoc, Total_Charge, Paid_Charge, day, month, year, hour, min, sec);
//		
//		pr_record_no++;
//		cin.ignore();
//
//	}
//	delete[]temp_array;
//}

void Patient::AddRecord(const char* temp_array, int ASSignDoc, mDate AssignDate, mTime AssignTime, float Total_Charge, float Paid_Charge)
{
	if (pr_record_history == nullptr)
	{
		pr_record_history = new pRecord*;
		pr_record_history[pr_record_no] = new pRecord(temp_array, ASSignDoc, Total_Charge, Paid_Charge, AssignDate.GetDay(), AssignDate.GetMonth(), AssignDate.GetYear(), AssignTime.GetHour(), AssignTime.GetMin(), AssignTime.GetSec());
		pr_record_no++;
		//cin.ignore();

	}
	else
	{
		pRecord** Temp_History;
		Temp_History = new pRecord * [pr_record_no];

		for (int i = 0; i < pr_record_no; i++)
		{
			Temp_History[i] = pr_record_history[i];
		}

		delete[]pr_record_history;
		pr_record_history = nullptr;

		pr_record_history = new pRecord * [pr_record_no + 1];
		for (int i = 0; i < pr_record_no; i++)
		{
			pr_record_history[i] = Temp_History[i];
		}
		pr_record_history[pr_record_no] = new pRecord(temp_array, ASSignDoc, Total_Charge, Paid_Charge, AssignDate.GetDay(), AssignDate.GetMonth(), AssignDate.GetYear(), AssignTime.GetHour(), AssignTime.GetMin(), AssignTime.GetSec());

		pr_record_no++;
		//cin.ignore();

	}
}

void Patient::DeleteRecord(int record_no)
{
	if (record_no > pr_record_no)
	{
		cout << "	Record Does Not Exist " << endl;
	}
	else
	{
		pRecord** Temp_Histor = new pRecord * [pr_record_no - 1];
		for (int i = 0; i < record_no - 1; i++)
		{
			Temp_Histor[i] = pr_record_history[i];
		}
		for (int i = record_no - 1; i < pr_record_no - 1; i++)
		{
			Temp_Histor[i] = pr_record_history[i + 1];
		}

		delete pr_record_history[record_no - 1];
		delete[]pr_record_history;
		pr_record_history = nullptr;

		pr_record_no--;
		pr_record_history = new pRecord * [pr_record_no + 1];

		for (int i = 0; i < pr_record_no; i++)
		{
			pr_record_history[i] = Temp_Histor[i];
		}

		delete[]Temp_Histor;
		Temp_Histor = nullptr;
	}
}

void Patient::Delete_Latest_Record()
{
	this->DeleteRecord(pr_record_no);
}

void Patient::printRecords()
{
	for (int i = 0; i < pr_record_no; i++)
	{
		cout << "	Record # " << i + 1 << endl;
		cout << "	-----------------------------------------" << endl;
		cout << pr_record_history[i][0];
		cout << "	-----------------------------------------" << endl;
		cout << endl;
	}
}

void Patient::print_specific_Record(int record_no)
{
	if (record_no > pr_record_no)
	{
		cout << "	Record Does Not Exist " << endl;
	}
	else
	{
		cout << "	Record # " << record_no << endl;
		cout << "	-----------------------------------------" << endl;
		cout << pr_record_history[record_no - 1][0];
		cout << "	-----------------------------------------" << endl;
		cout << endl;
	}
	
}

void Patient::print_latest_record()
{
	cout << "	Record # " << pr_record_no << endl;
	cout << "	-----------------------------------------" << endl;
	cout << pr_record_history[pr_record_no - 1][0];
	cout << "	-----------------------------------------" << endl;
	cout << endl;
}

void Patient::AddData()
{
	Person::AddData();
	cout << "	Enter Patient's ID : ";
	cin >> pr_pID;
}

void Patient::AddData(int pID, int age, int nID, int day, int month, int year, const char* fname, const char* lname)
{
	pr_pID = pID;
	Person::AddData(age, nID, day, month, year, fname, lname);
}

int Patient::GetpID()
{
	return pr_pID;
}

int Patient::GetNoOFRecords()
{
	return pr_record_no;
}

pRecord** Patient::GetRecords()
{
	return pr_record_history;
}

Patient::~Patient()
{
	if (pr_record_history != nullptr)
	{
		for (int i = 0; i < pr_record_no; i++)
		{
			delete pr_record_history[i];
		}
		delete[]pr_record_history;
		pr_record_history = nullptr;
	}
}

ostream& operator<<(ostream& out, Patient& obj_in)
{
	out << "	Patient's ID #          : " << obj_in.pr_pID << endl;
	out << static_cast<Person&>(obj_in);
	return out;
}

#include "Appointment.h"
#include<string>

Appointment::Appointment()
{
	pr_DiseaseType = nullptr;
	pr_pID = 0;
	pr_dID = 0;
	pr_TokenNumber = 0;
	pr_Fee = 0;
	pr_PaidFee = 0;
	pr_Status = false;
}

Appointment::Appointment(const char* disease , int pID, int dID, int day, int month, int year, int hours, int min, int sec, int token, float fee, float paid_fee)
{
	if (pr_DiseaseType != nullptr)
	{
		delete[]pr_DiseaseType;
		pr_DiseaseType = nullptr;
	}

	if (disease != nullptr)
	{
		pr_DiseaseType = new char[strlen(disease) + 1];
		for (int i = 0; disease[i] != '\0'; i++)
		{
			pr_DiseaseType[i] = disease[i];
		}
		pr_DiseaseType[strlen(disease)] = '\0';
	}
	else
	{
		pr_DiseaseType = nullptr;
	}

	pr_dID = dID;
	pr_pID = pID;
	pr_AppDate.SetDate(day, month, year);
	pr_AppTime.SetTime(hours, min, sec);
	pr_TokenNumber = token;
	pr_Fee = fee;
	pr_PaidFee = paid_fee;
	pr_Status = false; 
}

Appointment::Appointment(Appointment& obj_in)
{
	if (pr_DiseaseType != nullptr)
	{
		delete[]pr_DiseaseType;
		pr_DiseaseType = nullptr;
	}

	if (obj_in.pr_DiseaseType != nullptr)
	{
		pr_DiseaseType = new char[strlen(obj_in.pr_DiseaseType) + 1];
		for (int i = 0; obj_in.pr_DiseaseType[i] != '\0'; i++)
		{
			pr_DiseaseType[i] = obj_in.pr_DiseaseType[i];
		}
		pr_DiseaseType[strlen(obj_in.pr_DiseaseType)] = '\0';
	}
	else
	{
		pr_DiseaseType = nullptr;
	}

	pr_pID = obj_in.pr_pID;
	pr_dID = obj_in.pr_dID;
	pr_AppDate.CopyDate(obj_in.pr_AppDate);
	pr_AppTime.CopyTime(obj_in.pr_AppTime);
	pr_TokenNumber = obj_in.pr_TokenNumber;
	pr_Fee = obj_in.pr_Fee;
	pr_PaidFee = obj_in.pr_PaidFee;
	pr_Status = obj_in.pr_Status;
}

void Appointment::SetDiseaseType(const char* disease)
{
	if (pr_DiseaseType != nullptr)
	{
		delete[]pr_DiseaseType;
		pr_DiseaseType = nullptr;
	}

	if (disease != nullptr)
	{
		pr_DiseaseType = new char[strlen(disease) + 1];
		for (int i = 0; disease[i] != '\0'; i++)
		{
			pr_DiseaseType[i] = disease[i];
		}
		pr_DiseaseType[strlen(disease)] = '\0';
	}
	else
	{
		pr_DiseaseType = nullptr;
	}
}

void Appointment::SetpID(int pID)
{
	pr_pID = pID;
}

void Appointment::SetdID(int dID)
{
	pr_dID = dID;
}

void Appointment::SetAppDate(mDate& AppDate)
{
	pr_AppDate.CopyDate(AppDate);
}

void Appointment::SetAppTime(mTime& AppTime)
{
	pr_AppTime.CopyTime(AppTime);
}

void Appointment::SetAppDate(int day , int month, int year)
{
	pr_AppDate.SetDate(day, month, year);
}

void Appointment::SetAppTime(int hours, int min, int sec)
{
	pr_AppTime.SetTime(hours, min, sec);
}

void Appointment::SetTokenNo(int TokenNo)
{
	pr_TokenNumber = TokenNo;
}

void Appointment::SetFee(float Fee)
{
	pr_Fee = Fee;
}

void Appointment::SetPaidFee(float PaidFee)
{
	pr_PaidFee = PaidFee;
}

void Appointment::SetStatus(bool status)
{
	pr_Status = status;
}

void Appointment::AddData()
{
	char* Temp_array = new char[20];
	cout << "	Enter Disease Type : ";
	cin.getline(Temp_array, 20);
	this->SetDiseaseType(Temp_array);
	cout << "	Enter Patient's ID # : ";
	cin >> pr_pID;
	cout << "	Enter Doctor's ID # :  ";
	cin >> pr_dID;
	int day, month, year, hour, min, sec;
	cout << "	Enter Appointment Date (Day Month Year) : " << endl;
	cout << "	Day   : ";
	cin >> day;
	cout << "	Month : ";
	cin >> month;
	cout << "	Year  : ";
	cin >> year;
	pr_AppDate.SetDate(day, month, year);
	cout << "	Enter Appoinment Time (Hours Min Sec) :  " << endl;
	cout << "	Hours : ";
	cin >> hour;
	cout << "	Min   : ";
	cin >> min;
	cout << "	Sec   : ";
	cin >> sec;
	pr_AppTime.SetTime(hour, min, sec);
	cout << "	Enter Token Number  : ";
	cin >> pr_TokenNumber;
	cout << "	Enter Total Charges : ";
	cin >> pr_Fee;
	cout << "	Enter Paid Charges  : ";
	cin >> pr_PaidFee;

	delete[]Temp_array;
}

const char* Appointment::GetDiseaseType()
{
	return pr_DiseaseType;
}

int Appointment::GetpID()
{
	return pr_pID;
}

int Appointment::GetdID()
{
	return pr_dID;
}

mDate& Appointment::GetAppDate()
{
	return pr_AppDate;
}

mTime& Appointment::GetAppTime()
{
	return pr_AppTime;
}

int Appointment::GetTokenNo()
{
	return pr_TokenNumber;
}

float Appointment::GetFee()
{
	return pr_Fee;
}

float Appointment::GetPaidFee()
{
	return pr_PaidFee;
}

bool Appointment::GetStatus()
{
	return pr_Status;
}



ostream& operator<<(ostream& out, Appointment& obj_in)
{
	out << "	Disease Type     : "<<obj_in.pr_DiseaseType << endl;
	out << "	Patient's ID #   : " << obj_in.pr_pID << endl;
	out << "	Doctors's ID #   : " << obj_in.pr_dID << endl;
	out << "	Appointment Date : " << obj_in.pr_AppDate << endl;
	out << "	Appointment Time : " << obj_in.pr_AppTime << endl;
	out << "	Token Number     : " << obj_in.pr_TokenNumber << endl;
	out << "	Total Charges    : " << obj_in.pr_Fee << endl;
	out << "	Paid  Charges    : " << obj_in.pr_PaidFee << endl;
	return out;
}

Appointment::~Appointment()
{
	if (pr_DiseaseType != nullptr)
	{
		delete[]pr_DiseaseType;
	}
}
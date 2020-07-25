#include "Doctor.h"
#include"Person.h"
#include"Name.h"
#include<string>

Doctor::Doctor()
{
	pr_dID = 0;
	pr_specialization = nullptr;
	pr_vistedPatient_record = nullptr;
	pr_NoOfRecords = 0;
}

Doctor::Doctor(int dID, const char* special, int age, int nID, int day, int month, int year, const char* fname, const char* lname) :Person(age, nID, day, month, year, fname, lname)
{
	pr_dID = dID;
	if (special != nullptr)
	{
		pr_specialization = new char[strlen(special) + 1];
		for (int i = 0; special[i] != '\0'; i++)
		{
			pr_specialization[i] = special[i];
		}
		pr_specialization[strlen(special)] = '\0';
	}
	pr_NoOfRecords = 0;
	pr_vistedPatient_record = nullptr;
}

Doctor::Doctor(Doctor& obj_in) :Person(obj_in)
{
	pr_dID = obj_in.pr_dID;
	if (obj_in.pr_specialization != nullptr)
	{
		pr_specialization = new char[strlen(obj_in.pr_specialization) + 1];
		for (int i = 0; obj_in.pr_specialization[i] != '\0'; i++)
		{
			pr_specialization[i] = obj_in.pr_specialization[i];
		}
		pr_specialization[strlen(obj_in.pr_specialization)] = '\0';
	}
	else
	{
		pr_specialization = nullptr;
	}

	if (obj_in.pr_NoOfRecords != 0)
	{
		pr_NoOfRecords = obj_in.pr_NoOfRecords;
		pr_vistedPatient_record = new int[obj_in.pr_NoOfRecords];
		for (int i = 0; i < obj_in.pr_NoOfRecords; i++)
		{
			pr_vistedPatient_record[i] = obj_in.pr_vistedPatient_record[i];
		}
	}
	else
	{
		pr_NoOfRecords = 0;
		pr_vistedPatient_record = nullptr;
	}
}

void Doctor::AddPatient_record(int ID)
{
	if (pr_vistedPatient_record == nullptr)
	{
		pr_vistedPatient_record = new int(ID);
		pr_NoOfRecords++;
	}
	else
	{
		int* temp_int_array = new int[pr_NoOfRecords];
		for (int i = 0; i < pr_NoOfRecords; i++)
		{
			temp_int_array[i] = pr_vistedPatient_record[i];
		}

		delete[]pr_vistedPatient_record;
		pr_vistedPatient_record = nullptr;

		pr_vistedPatient_record = new int[pr_NoOfRecords + 1];
		for(int i=0;i<pr_NoOfRecords;i++)
		{
			pr_vistedPatient_record[i] = temp_int_array[i];
		}
		pr_vistedPatient_record[pr_NoOfRecords] = ID;

		pr_NoOfRecords++;

		delete[]temp_int_array;
	}

}

void Doctor::DeletePatient_record()
{
	int ID, key = 0;
	cout << "	Enter Patient's ID # : ";
	cin >> ID;
	for (int i = 0; i < pr_NoOfRecords; i++)
	{
		if (pr_vistedPatient_record[i] == ID)
		{
			key = i;
			break;
		}
	}

	int* temp_int_array = new int[pr_NoOfRecords - 1];

	for (int i = 0; i < key; i++)
	{
		temp_int_array[i] = pr_vistedPatient_record[i];
	}

	for(int i=key+1;i<pr_NoOfRecords;i++)
	{
		temp_int_array[i - 1] = pr_vistedPatient_record[i];
	}

	delete[]pr_vistedPatient_record;
	pr_vistedPatient_record = nullptr;

	pr_vistedPatient_record = new int[pr_NoOfRecords - 1];
	pr_NoOfRecords--;
	for (int i = 0; i < pr_NoOfRecords; i++)
	{
		pr_vistedPatient_record[i] = temp_int_array[i];
	}
}

void Doctor::PrintVisitedPatient_record()
{
	for (int i = 0; i < pr_NoOfRecords; i++)
	{
		cout << "	Patient    # : " << i + 1 << endl;
		cout << "	------------------" << endl;
		cout << "	Patient ID # : "<<pr_vistedPatient_record[i] << endl;
		cout << "	------------------" << endl;
		cout << endl;
	}
}

void Doctor::SetdID(int dID)
{
	pr_dID = dID;
}

void Doctor::SetSpecialization(const char* specialization)
{
	pr_specialization = new char[strlen(specialization) + 1];
	for (int i = 0; specialization[i] != '\0'; i++)
	{
		pr_specialization[i] = specialization[i];
	}
	pr_specialization[strlen(specialization)] = '\0';

}

void Doctor::AddData()
{
	Person::AddData();
	cout << "	Enter Doctor's ID # : ";
	cin >> pr_dID;
	cin.ignore();
	char* temp_array = new char[20];
	cout << "	Enter Doctor's Specialization Field : ";
	cin.getline(temp_array, 20);
	this->SetSpecialization(temp_array);
}

void Doctor::AddData(int dID, const char* special, int age, int nID, int day, int month, int year, const char* fname, const char* lname)
{
	pr_dID = dID;
	if (special != nullptr)
	{
		pr_specialization = new char[strlen(special) + 1];
		for (int i = 0; special[i] != '\0'; i++)
		{
			pr_specialization[i] = special[i];
		}
		pr_specialization[strlen(special)] = '\0';
	}
	pr_NoOfRecords = 0;
	Person::AddData(age, nID, day, month, year, fname, lname);
}

int Doctor::GetdID()
{
	return pr_dID;
}

const char* Doctor::GetSpecialization()
{
	return pr_specialization;
}

int Doctor::GetNoOfRecords()
{
	return pr_NoOfRecords;
}

int* Doctor::GetRecords()
{
	return pr_vistedPatient_record;
}

ostream& operator<<(ostream& out, Doctor& obj_in)
{
	out << "	Doctors ID #            : " << obj_in.pr_dID << endl;
	out << "	Doctor's Specialization : " << obj_in.pr_specialization << endl;
	out << static_cast<Person&>(obj_in) << endl;
	return out;
}

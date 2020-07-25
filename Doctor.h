#pragma once
#include"Name.h"
#include"Person.h"
#include<iostream>

using namespace std;
class Doctor: public Person
{
	private:
		int pr_dID;
		char* pr_specialization;
		int* pr_vistedPatient_record;
		int pr_NoOfRecords;
	public:
		Doctor();
		Doctor(int, const char*,  int, int, int, int, int, const char*, const char*);
		Doctor(Doctor&);

		void AddPatient_record(int);
		void DeletePatient_record();
		void PrintVisitedPatient_record();
		void SetdID(int);
		void SetSpecialization(const char*);
		void AddData();
		void AddData(int, const char*, int, int, int, int, int, const char*, const char*);

		int GetdID();
		const char* GetSpecialization();
		int GetNoOfRecords();
		int* GetRecords();

		friend ostream& operator <<(ostream&, Doctor&);
};


#pragma once
#include"Person.h"
#include"pRecord.h"
#include<iostream>

using namespace std;
class Patient : public Person
{
	private:
		int pr_pID;
		pRecord** pr_record_history;
		int pr_record_no;
	public:
		Patient();
		Patient(int, int, int, int, int, int, const char*, const char*);
		Patient(int);
		Patient(Patient&);

		void SetpID(int);
		//void AddRecord();
		void AddRecord(const char*, int, mDate, mTime, float, float);
		void DeleteRecord(int);
		void Delete_Latest_Record();
		void printRecords();
		void print_specific_Record(int);
		void print_latest_record();
		void AddData();
		void AddData(int, int, int, int, int, int, const char*, const char*);

		int GetpID();
		int GetNoOFRecords();
		pRecord** GetRecords();

		friend ostream& operator <<(ostream&, Patient&);


		~Patient();


};


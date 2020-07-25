#pragma once
#include"mDate.h"
#include"mTime.h"
#include<iostream>

using namespace std;

class Appointment
{
	private:
		char* pr_DiseaseType;
		int pr_pID;
		int pr_dID;
		mDate pr_AppDate;
		mTime pr_AppTime;
		int pr_TokenNumber;
		float pr_Fee;
		float pr_PaidFee;
		bool pr_Status;
	public:
		Appointment();
		Appointment(const char*, int, int, int, int, int, int, int, int, int, float, float);
		Appointment(Appointment&);

		void SetDiseaseType(const char*);
		void SetpID(int);
		void SetdID(int);
		void SetAppDate(mDate&);
		void SetAppTime(mTime&);
		void SetAppDate(int, int, int);
		void SetAppTime(int, int, int);
		void SetTokenNo(int);
		void SetFee(float);
		void SetPaidFee(float);
		void SetStatus(bool);
		void AddData();

		const char* GetDiseaseType();
		int GetpID();
		int GetdID();
		mDate& GetAppDate();
		mTime& GetAppTime();
		int GetTokenNo();
		float GetFee();
		float GetPaidFee();
		bool GetStatus();

		friend ostream& operator<<(ostream&, Appointment&);

		~Appointment();
};


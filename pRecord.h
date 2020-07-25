#pragma once
#include<iostream>

#include"mDate.h"
#include"mTime.h"

using namespace std;

class pRecord
{
	private:
		char* pr_DiseaseType;
		mDate pr_Vis_Date;
		mTime pr_Vis_Time;
		int pr_AssignedDoc;
		float pr_TotalCharges;
		float pr_PaidCharges;
	public:
		pRecord();
		pRecord(const char*, int, float, float, int, int, int, int, int, int);
		pRecord(pRecord&);

		void SetDiseaseType(const char *);
		void SetDoc(int);
		void SetVisDate(int, int, int);
		void SetVisTime(int, int, int);
		void SetTotalCharges(float);
		void SetPaidCharges(float);

		const char* GetDiseaseType();
		int GetDoc();
		mDate GetVisDate();
		mTime GetVisTime();
		float GetTotalCharges();
		float GetPaidCharges();

		friend ostream& operator <<(ostream&, pRecord&);

		~pRecord();
};


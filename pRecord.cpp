#include "pRecord.h"
#include<string>


pRecord::pRecord()
{
	pr_AssignedDoc = 0;
	pr_DiseaseType = nullptr;
	pr_PaidCharges = 0;
	pr_TotalCharges = 0;
}

pRecord::pRecord(const char* disease, int AsignDoc, float TotalCharges, float PaidChares, int day, int month, int year, int hour, int min, int sec) 
{
	pr_Vis_Date.SetDate(day, month, year);

	pr_Vis_Time.SetTime(hour, min, sec);

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

	pr_AssignedDoc = AsignDoc;
	pr_TotalCharges = TotalCharges;
	pr_PaidCharges = PaidChares;
}

pRecord::pRecord(pRecord& obj_in) 
{
	pr_Vis_Date.CopyDate(obj_in.pr_Vis_Date);

	pr_Vis_Time.CopyTime(obj_in.pr_Vis_Time);

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

	pr_AssignedDoc = obj_in.pr_AssignedDoc;
	pr_PaidCharges = obj_in.pr_PaidCharges;
	pr_TotalCharges = obj_in.pr_TotalCharges;
}

void pRecord::SetDiseaseType(const char* disease)
{
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

void pRecord::SetDoc(int AsignedDoc)
{
	pr_AssignedDoc = AsignedDoc;
}

void pRecord::SetVisDate(int day, int mon, int year)
{
	pr_Vis_Date.SetDate(day, mon, year);
}

void pRecord::SetVisTime(int hours, int min, int sec)
{
	pr_Vis_Time.SetTime(hours, min, sec);
}

void pRecord::SetTotalCharges(float Total)
{
	pr_TotalCharges = Total;
}

void pRecord::SetPaidCharges(float paid)
{
	pr_PaidCharges = paid;
}

const char* pRecord::GetDiseaseType()
{
	return pr_DiseaseType;
}

int pRecord::GetDoc()
{
	return pr_AssignedDoc;
}

mDate pRecord::GetVisDate()
{
	return pr_Vis_Date;
}

mTime pRecord::GetVisTime()
{
	return pr_Vis_Time;
}

float pRecord::GetTotalCharges()
{
	return pr_TotalCharges;
}

float pRecord::GetPaidCharges()
{
	return pr_PaidCharges;
}

pRecord::~pRecord()
{
	if (pr_DiseaseType != nullptr)
	{
		delete[]pr_DiseaseType;
	}
}

ostream& operator<<(ostream& out, pRecord& obj_in)
{
	out << "	Disease             : " << obj_in.pr_DiseaseType << endl;
	out << "	Assigned Doctors ID : " << obj_in.pr_AssignedDoc << endl;
	out << "	Visiting Date       : " << obj_in.pr_Vis_Date << endl;
	out << "	Visiing Time        : " << obj_in.pr_Vis_Time << endl;
	out << "	Total Chargers      : " << obj_in.pr_TotalCharges << endl;
	out << "	Paid Charges        : " << obj_in.pr_PaidCharges << endl;
	if (obj_in.pr_PaidCharges > obj_in.pr_TotalCharges)
	{
		out << "	Amount Returned     : "<<obj_in.pr_PaidCharges-obj_in.pr_TotalCharges << endl;
	}
	else
	{
		out << "	Amount To Be Paid   : " << obj_in.pr_TotalCharges - obj_in.pr_PaidCharges << endl;
	}
	return out;
}

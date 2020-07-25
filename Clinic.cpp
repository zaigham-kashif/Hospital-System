#include "Clinic.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

Clinic::Clinic()
{
	pr_Doctor_List = nullptr;
	pr_NoOfDoctors = 0;
	pr_Patient_List = nullptr;
	pr_NoOfPatients = 0;
	pr_Appointment_List = nullptr;
	pr_NoOFAppointments = 0;
}

int Clinic::getNoOfDoctors()
{
	return pr_NoOfDoctors;
}

int Clinic::getNoOfPatients()
{
	return pr_NoOfPatients;
}

int Clinic::getNoOfAppointments()
{
	return pr_NoOFAppointments;
}

Doctor** Clinic::getDoctors()
{
	return pr_Doctor_List;
}

Patient** Clinic::getPatient()
{
	return pr_Patient_List;
}

Appointment** Clinic::getAppointment()
{
	return pr_Appointment_List;
}



void Clinic::AddDoctor(const char* temp_array1, const char* temp_array2, int day, int month, int year, int NID, int Age, int dID, const char* temp_array)
{

	if (pr_Doctor_List == nullptr)
	{
		pr_Doctor_List = new Doctor*;
		pr_Doctor_List[pr_NoOfDoctors]=new Doctor ;
		pr_Doctor_List[pr_NoOfDoctors][0].AddData(dID, temp_array, Age, NID, day, month, year, temp_array1, temp_array2);
		pr_NoOfDoctors++;
	}
	else
	{
		Doctor **Temp_Doctor_List;
		Temp_Doctor_List = new Doctor * [pr_NoOfDoctors];
		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			Temp_Doctor_List[i] = pr_Doctor_List[i];
		}

		delete[]pr_Doctor_List;
		pr_Doctor_List = nullptr;

		pr_Doctor_List = new Doctor * [pr_NoOfDoctors + 1];

		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			pr_Doctor_List[i] = Temp_Doctor_List[i];
		}

		pr_Doctor_List[pr_NoOfDoctors] = new Doctor;
		pr_Doctor_List[pr_NoOfDoctors][0].AddData(dID, temp_array, Age, NID, day, month, year, temp_array1, temp_array2);

		pr_NoOfDoctors++;

		delete[]Temp_Doctor_List;
		Temp_Doctor_List = nullptr;
	}

}

void Clinic::AddPatient(const char* temp_array1, const char* temp_array2, int day, int month, int year, int NID, int Age, int pID)
{

	if (pr_Patient_List == nullptr)
	{
		pr_Patient_List = new Patient * [1];
		pr_Patient_List[0] = new Patient;
		pr_Patient_List[0][0].AddData(pID, Age, NID, day, month, year, temp_array1, temp_array2);
		pr_NoOfPatients++;
	}
	else
	{
		Patient** Temp_Patient_List;
		Temp_Patient_List = new Patient * [pr_NoOfPatients];
		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			Temp_Patient_List[i] = pr_Patient_List[i];
		}

		delete[]pr_Patient_List;
		pr_Patient_List = nullptr;

		pr_Patient_List = new Patient * [pr_NoOfPatients + 1];

		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			pr_Patient_List[i] = Temp_Patient_List[i];
		}

		pr_Patient_List[pr_NoOfPatients] = new Patient;
		pr_Patient_List[pr_NoOfPatients][0].AddData(pID, Age, NID, day, month, year, temp_array1, temp_array2);

		pr_NoOfPatients++;

		delete[]Temp_Patient_List;
		Temp_Patient_List = nullptr;
	}
}

void Clinic::AddAppointment(const char* Temp_array, int pID, int dID, int day, int month, int year, int hour, int min, int sec, int TokenNO, float Fee, float Paid_Fee)
{
	

	if (pr_Appointment_List == nullptr)
	{
		pr_Appointment_List = new Appointment*;
		pr_Appointment_List[0] = new Appointment(Temp_array, pID, dID, day, month, year, hour, min, sec, TokenNO, Fee, Paid_Fee);
		pr_NoOFAppointments++;
	}
	else
	{
		Appointment** Temp_Appointment_List;
		Temp_Appointment_List = new Appointment * [pr_NoOFAppointments];
		for (int i = 0; i < pr_NoOFAppointments; i++)
		{
			Temp_Appointment_List[i] = pr_Appointment_List[i];
		}

		delete[]pr_Appointment_List;
		pr_Appointment_List = nullptr;

		pr_Appointment_List = new Appointment * [pr_NoOFAppointments + 1];
		for (int i = 0; i < pr_NoOFAppointments; i++)
		{
			pr_Appointment_List[i] = Temp_Appointment_List[i];
		}

		pr_Appointment_List[pr_NoOFAppointments] = new Appointment(Temp_array, pID, dID, day, month, year, hour, min, sec, TokenNO, Fee, Paid_Fee);

		pr_NoOFAppointments++;

		delete[]Temp_Appointment_List;
		Temp_Appointment_List = nullptr;
	}
}

void Clinic::RemoveDoctor()
{
	int dID = 0,key=-1;
	cout << "	Enter Doctor's ID to be removed : ";
	cin >> dID;

	if (pr_NoOfDoctors == 1 && dID == pr_Doctor_List[0][0].GetdID())
	{
		delete pr_Doctor_List[0];
		delete[]pr_Doctor_List;
		pr_Doctor_List = nullptr;

		pr_NoOfDoctors = 0;
	}
	else
	{
		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			if (dID == pr_Doctor_List[i][0].GetdID())
			{
				key = i;
			}
		}

		if (key == -1)
		{
			cout << "	Doctor Does Not Exist " << endl;
		}
		else
		{
			Doctor** Temp_doctor_List;
			Temp_doctor_List = new Doctor * [pr_NoOfDoctors - 1];
			for (int i = 0; i < key; i++)
			{
				Temp_doctor_List[i] = pr_Doctor_List[i];
			}

			for (int i = key + 1; i < pr_NoOfDoctors; i++)
			{
				Temp_doctor_List[i - 1] = pr_Doctor_List[i];
			}

			delete pr_Doctor_List[key];
			delete[]pr_Doctor_List;
			pr_Doctor_List = nullptr;

			pr_Doctor_List = new Doctor * [pr_NoOfDoctors - 1];
			pr_NoOfDoctors--;

			for (int i = 0; i < pr_NoOfDoctors; i++)
			{
				pr_Doctor_List[i] = Temp_doctor_List[i];
			}

			delete[]Temp_doctor_List;
			Temp_doctor_List = nullptr;
		}
	}
}

void Clinic::RemovePatient()
{
	int pID = 0, key = -1;
	cout << "	Enter Patient's ID to be removed : ";
	cin >> pID;

	if (pr_NoOfPatients == 1 && pID == pr_Patient_List[0][0].GetpID())
	{
		delete pr_Patient_List[0];
		delete[]pr_Patient_List;
		pr_Patient_List = nullptr;

		pr_NoOfPatients = 0;
	}
	else
	{
		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			if (pID == pr_Patient_List[i][0].GetpID())
			{
				key = i;
			}
		}

		if (key == -1)
		{
			cout << "	Patient Does Not Exist " << endl;
		}
		else
		{
			Patient** Temp_Patient_List;
			Temp_Patient_List = new Patient * [pr_NoOfPatients - 1];
			for (int i = 0; i < key; i++)
			{
				Temp_Patient_List[i] = pr_Patient_List[i];
			}

			for (int i = key + 1; i < pr_NoOfPatients; i++)
			{
				Temp_Patient_List[i - 1] = pr_Patient_List[i];
			}

			delete pr_Patient_List[key];
			delete[]pr_Patient_List;
			pr_Patient_List = nullptr;

			pr_Patient_List = new Patient * [pr_NoOfPatients - 1];
			pr_NoOfPatients--;

			for (int i = 0; i < pr_NoOfPatients; i++)
			{
				pr_Patient_List[i] = Temp_Patient_List[i];
			}

			delete[]Temp_Patient_List;
			Temp_Patient_List = nullptr;
		}
	}
}

void Clinic::DeleteAppointment(int token_no)
{
	int key = -1;

	if (pr_NoOFAppointments == 1 && pr_Appointment_List[0][0].GetTokenNo() == token_no && pr_Appointment_List[0][0].GetStatus() == true)
	{
		delete pr_Appointment_List[0];
		delete[]pr_Appointment_List;
		pr_Appointment_List = nullptr;

		pr_NoOFAppointments = 0;
	}
	else if (pr_NoOFAppointments == 1 && pr_Appointment_List[0][0].GetTokenNo() != token_no)
	{
		cout << "	Appointment with such Token Number Does Not Exist " << endl;
	}
	else if (pr_NoOFAppointments == 1 && pr_Appointment_List[0][0].GetStatus() == false)
	{
		cout << "	    Appointment has not been compleated yet" << endl;
	}
	else
	{
		for (int i = 0; i < pr_NoOFAppointments; i++)
		{
			if (token_no == pr_Appointment_List[i][0].GetTokenNo())
			{
				key = i;
			}
		}

		if (key == -1)
		{
			cout << "	Appointment with such Token Number Does Not Exist " << endl;
		}
		else
		{
			if (pr_Appointment_List[key][0].GetStatus() == false)
			{
				cout << "	This Appointment is still pending and can not be deleted" << endl;
			}
			else
			{
				Appointment** Temp_Appointment_List;
				Temp_Appointment_List = new Appointment * [pr_NoOFAppointments - 1];
				for (int i = 0; i < key; i++)
				{
					Temp_Appointment_List[i] = pr_Appointment_List[i];
				}

				for (int i = key + 1; i < pr_NoOFAppointments; i++)
				{
					Temp_Appointment_List[i - 1] = pr_Appointment_List[i];
				}

				delete pr_Appointment_List[key];
				delete[]pr_Appointment_List;
				pr_Appointment_List = nullptr;

				pr_Appointment_List = new Appointment * [pr_NoOFAppointments - 1];
				pr_NoOFAppointments--;

				for (int i = 0; i < pr_NoOFAppointments; i++)
				{
					pr_Appointment_List[i] = Temp_Appointment_List[i];
				}

				delete[]Temp_Appointment_List;
				Temp_Appointment_List = nullptr;
			}
		}
	}

}

void Clinic::PrintDoctorList()
{
	if (pr_NoOfDoctors == 0)
	{
		cout << "	       There Is no record of Doctors " << endl;
		cout << "	Record of doctors can be added from main menu" << endl;
	}

	for (int i = 0; i < pr_NoOfDoctors; i++)
	{
		cout << "	Doctor # " << i + 1 << endl;
		cout << "	------------------------------------------" << endl;
		cout << pr_Doctor_List[i][0];
		cout << "	------------------------------------------" << endl;
		cout << endl;
	}
}

void Clinic::PrintPatientList()
{
	if (pr_NoOfPatients == 0)
	{
		cout << "	       There Is no record of Patients " << endl;
		cout << "	Record of patients can be added from main menu"<<endl;
	}

	for (int i = 0; i < pr_NoOfPatients; i++)
	{
		cout << "	Patient # " << i + 1 << endl;
		cout << "	------------------------------------------" << endl;
		cout << pr_Patient_List[i][0];
		cout << "	------------------------------------------" << endl;
		cout << endl;
	}
}

void Clinic::PrintAppointmentList()
{
	if (pr_NoOFAppointments==0)
	{
		cout << "	     No Appointments Have been Added" << endl;
		cout << "	You Can Add New Appointments from main menu" << endl;
	}

	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		cout << "	Appointment # " << i + 1 << endl;
		cout << "	------------------------------------------" << endl;
		cout << pr_Appointment_List[i][0];
		cout << "	------------------------------------------" << endl;
		cout << endl;
	}
}

void Clinic::MarkAppointmentDone()
{
	int token_no = 0, key = -1, patient_id = 0, doctor_id = 0, key_d = -1, key_p = -1;
	cout << "	Enter Token # of Appointment to be marked done : ";
	cin >> token_no;
	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (pr_Appointment_List[i][0].GetTokenNo() == token_no)
		{
			key = i;
		}
	}

	if (key == -1)
	{
		cout << "	No Appointment with this Token No Exist " << endl;
	}
	else
	{
		patient_id = pr_Appointment_List[key][0].GetpID();
		doctor_id = pr_Appointment_List[key][0].GetdID();

		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			if (doctor_id == pr_Doctor_List[i][0].GetdID())
			{
				key_d = i;
				break;
			}
		}

		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			if (patient_id == pr_Patient_List[i][0].GetpID())
			{
				key_p = i;
				break;
			}
		}

		pr_Doctor_List[key_d][0].AddPatient_record(patient_id);

		char* temp_arary = new char[strlen(pr_Appointment_List[key][0].GetDiseaseType()) + 1];
		for (int i = 0; i < strlen(pr_Appointment_List[key][0].GetDiseaseType()); i++)
		{
			temp_arary[i] = pr_Appointment_List[key][0].GetDiseaseType()[i];
		}
		temp_arary[strlen(pr_Appointment_List[key][0].GetDiseaseType())] = '\0';


		pr_Patient_List[key_p][0].AddRecord(temp_arary, pr_Appointment_List[key][0].GetdID(), pr_Appointment_List[key][0].GetAppDate(), pr_Appointment_List[key][0].GetAppTime(), pr_Appointment_List[key][0].GetFee(), pr_Appointment_List[key][0].GetPaidFee());
		pr_Appointment_List[key][0].SetStatus(true);

		int option = 0;

		do
		{
			cout << "	Delete This Appointment" << endl;
			cout << "	1-> Yes" << endl;
			cout << "	2-> No" << endl;
			cout << "	 -> ";
			cin >> option;
			if (option == 1)
			{
				this->DeleteAppointment(pr_Appointment_List[key][0].GetTokenNo());
			}

			if (option != 1 && option != 2)
			{
				cout << "	Invalid Option Selected " << endl;
			}
		} while (option != 1 && option != 2);

		delete[]temp_arary;
		temp_arary = nullptr;

	}
	
}

void Clinic::PrintPendingAppointments()
{
	int count = 0;
	if (pr_NoOFAppointments == 0)
	{
		cout << "	There are no appointments in the list" << endl;
	}

	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (pr_Appointment_List[i][0].GetStatus() == false)
		{
			count++;
			cout << "	Appointment # " << i + 1 << endl;
			cout << "	------------------------------------------" << endl;
			cout << pr_Appointment_List[i][0];
			cout << "	------------------------------------------" << endl;
			cout << endl;
		}
	}

	if (count == 0 && pr_NoOFAppointments != 0)
	{
		cout << "	There Are No Pending Appointments" << endl;
	}
}

void Clinic::PrintAppointmentsofDoctor(int dID)
{
	int count = 0;
	if (pr_NoOFAppointments == 0)
	{
		cout << "	There are no appointments in the list " << endl;
	}

	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (pr_Appointment_List[i][0].GetdID() == dID && pr_Appointment_List[i][0].GetStatus() == false)
		{
			count++;
			cout << "	Appointment # " << i + 1 << endl;
			cout << "	------------------------------------------" << endl;
			cout << pr_Appointment_List[i][0];
			cout << "	------------------------------------------" << endl;
			cout << endl;
		}
	}

	if (pr_NoOFAppointments != 0 && count == 0)
	{
		cout << "	There are no pending appointments of this doctor" << endl;
	}


}

void Clinic::PrintAppointmentsofPatient(int pID)
{
	int count = 0;
	if (pr_NoOFAppointments == 0)
	{
		cout << "	There are no appointments in the list " << endl;
	}

	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (pr_Appointment_List[i][0].GetpID() == pID && pr_Appointment_List[i][0].GetStatus() == false)
		{
			count++;
			cout << "	Appointment # " << i + 1 << endl;
			cout << "	------------------------------------------" << endl;
			cout << pr_Appointment_List[i][0];
			cout << "	------------------------------------------" << endl;
			cout << endl;
		}
	}

	if (pr_NoOFAppointments != 0 && count == 0)
	{
		cout << "	There are no pending appointments of this patient" << endl;
	}
}

void Clinic::PrintAppointmentsofDay(int day, int month, int year)
{
	int count = 0;
	if (pr_NoOFAppointments == 0)
	{
		cout << "	There are no appointments in the list " << endl;
	}

	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (pr_Appointment_List[i][0].GetAppDate().GetDay() == day && pr_Appointment_List[i][0].GetAppDate().GetMonth()==month&& pr_Appointment_List[i][0].GetAppDate().GetYear()==year && pr_Appointment_List[i][0].GetStatus() == false)
		{
			count++;
			
			cout << "	Appointment # " << i + 1 << endl;
			cout << "	------------------------------------------" << endl;
			cout << pr_Appointment_List[i][0];
			cout << "	------------------------------------------" << endl;
			cout << endl;
		}
	}

	if (pr_NoOFAppointments != 0 && count == 0)
	{
		cout << "	There are no pending appointments of this patient" << endl;
	}
}

void Clinic::PrintPatientVisByDoc(int dID, int day, int month, int year)
{
	int count = 0;
	for (int i = 0; i < pr_NoOfPatients; i++)
	{
		for (int j = 0; j < pr_Patient_List[i][0].GetNoOFRecords(); j++)
		{
			if (pr_Patient_List[i][0].GetRecords()[j][0].GetDoc() == dID && pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetDay() == day && pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetMonth() == month && pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetYear() == year)
			{
				count++;
				cout << "	------------------------------------------" << endl;
				cout << pr_Patient_List[i][0];
				cout << "	------------------------------------------" << endl;
				cout << endl;
			}
			
		}
	}

	if (count == 0)
	{
		cout << "	This Doctor Has Not Visited Any Patient on this Date" << endl;
	}
}

void Clinic::PrintPVisByDoc(int dID)
{
	int count = 0;
	for (int i = 0; i < pr_NoOfPatients; i++)
	{
		for (int j = 0; j < pr_Patient_List[i][0].GetNoOFRecords(); j++)
		{
			if (pr_Patient_List[i][0].GetRecords()[j][0].GetDoc() == dID)
			{
				count++;
				cout << "	------------------------------------------" << endl;
				cout << pr_Patient_List[i][0];
				cout << "	------------------------------------------" << endl;
				cout << endl;
			}

		}
	}

	if (count == 0)
	{
		cout << "	This Doctor Has Not Visited Any Patient on this Date" << endl;
	}
}

void Clinic::PatientRecordHistory(int pID)
{
	int key = -1;

	if (pr_NoOfPatients == 0)
	{
		cout << "	There is no data of Patients" << endl;
		cout << "	Add Data From Main Menu     " << endl;
	}
	else
	{
		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			if (pr_Patient_List[i][0].GetpID() == pID)
			{
				key = i;
				break;
			}
		}

		if (key == -1 && pr_NoOfPatients != 0)
		{
			cout << "	There is no Patient with this ID no " << endl;
		}
		else
		{
			pr_Patient_List[key][0].printRecords();

		}
	}
	

}

void Clinic::DoctorRecordHistory(int dID)
{
	int key = -1;

	if (pr_NoOfDoctors == 0)
	{
		cout << "	There is no data of Doctors" << endl;
		cout << "	Add Data From Main Menu     " << endl;
	}
	else
	{
		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			if (pr_Doctor_List[i][0].GetdID() == dID)
			{
				key = i;
				break;
			}
		}

		if (key == -1 && pr_NoOfDoctors != 0)
		{
			cout << "	There is no Doctor with this ID no " << endl;
		}
		else
		{
			cout << "	List of IDs Of Patient visited by doctor : " << endl;
			cout << endl;
			pr_Doctor_List[key][0].PrintVisitedPatient_record();
		}
	}

}

void Clinic::AddDoctorToFile(const char* temp_array1, const char* temp_array2, int day, int month, int year, int NID, int Age, int dID, const char* Temp_array)
{
	ofstream fout;
	fout.open("doctor.txt", ios::app);
	if (pr_NoOfDoctors > 1)
	{
		fout << endl;
	}
	fout << NID;
	fout << " ";
	fout << temp_array1;
	fout << " ";
	fout << temp_array2;
	fout << " ";
	fout << day;
	fout << " ";
	fout << month;
	fout << " ";
	fout << year;
	fout << " ";
	fout << Age;
	fout << " ";
	fout << dID;
	fout << " ";
	fout << Temp_array;
	fout.close();
}

void Clinic::AddPatientToFile(const char* temp_array1, const char* temp_array2, int day, int month, int year, int NID, int Age, int pID)
{
	ofstream fout;
	fout.open("patient.txt");
	fout << pID;
	fout << temp_array1;
	fout << temp_array2;
	fout << day;
	fout << month;
	fout << year;
	fout << Age;
	fout << NID;
}

void Clinic::AddAllDoctorsToFile()
{
	ofstream fout;
	fout.open("doctor.txt");
	for (int i = 0; i < pr_NoOfDoctors; i++)
	{
		if (i != 0)
		{
			fout << endl;
		}

		fout << pr_Doctor_List[i][0].GetdID();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetName().Get_fname();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetName().Get_lname();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetDOB().GetDay();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetDOB().GetMonth();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetDOB().GetYear();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetAge();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetNid();
		fout << " ";
		fout << pr_Doctor_List[i][0].GetSpecialization();
	}

	fout.close();
}

void Clinic::AddAllPatientsToFile()
{
	ofstream fout;
	fout.open("patient.txt");
	for (int i = 0; i < pr_NoOfPatients; i++)
	{
		if (i != 0)
		{
			fout << endl;
		}

		fout << pr_Patient_List[i][0].GetpID();
		fout << " ";
		fout << pr_Patient_List[i][0].GetName().Get_fname();
		fout << " ";
		fout << pr_Patient_List[i][0].GetName().Get_lname();
		fout << " ";
		fout << pr_Patient_List[i][0].GetDOB().GetDay();
		fout << " ";
		fout << pr_Patient_List[i][0].GetDOB().GetMonth();
		fout << " ";
		fout << pr_Patient_List[i][0].GetDOB().GetYear();
		fout << " ";
		fout << pr_Patient_List[i][0].GetAge();
		fout << " ";
		fout << pr_Patient_List[i][0].GetNid();
		fout << " ";
		fout << pr_Patient_List[i][0].GetNoOFRecords();
	}
}



void Clinic::AddAllAppointmentsToFile()
{
	ofstream fout;
	fout.open("appointment.txt");
	for (int i = 0; i < pr_NoOFAppointments; i++)
	{
		if (i != 0)
		{
			fout << endl;
		}
		fout << pr_Appointment_List[i][0].GetDiseaseType();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetpID();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetdID();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppDate().GetDay();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppDate().GetMonth();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppDate().GetYear();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppTime().GetHour();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppTime().GetMin();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetAppTime().GetSec();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetTokenNo();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetFee();
		fout << " ";
		fout << pr_Appointment_List[i][0].GetPaidFee();
	}
	fout.close();
}

void Clinic::AddAllpRecordsToFile()
{
	ofstream fout;
	fout.open("phistory.txt");
	for (int i = 0; i < pr_NoOfPatients; i++)
	{
		for (int j = 0; j < pr_Patient_List[i][0].GetNoOFRecords(); j++)
		{
			fout << endl;
			fout << pr_Patient_List[i][0].GetpID();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetDiseaseType();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetDay();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetMonth();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisDate().GetYear();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisTime().GetHour();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisTime().GetMin();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetVisTime().GetSec();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetDoc();
			fout << " ";
			fout << pr_Patient_List[i][0].GetRecords()[j][0].GetTotalCharges();
		}
	}
}

void Clinic::AddAlldRecordsToFile()
{
	ofstream fout;
	fout.open("dhistory.txt");

	for (int i = 0; i < pr_NoOfDoctors; i++)
	{
		for (int j = 0; j < pr_Doctor_List[i][0].GetNoOfRecords(); j++)
		{
			fout << endl;
			fout << pr_Doctor_List[i][0].GetdID();
			fout << " ";
			fout << pr_Doctor_List[i][0].GetRecords()[j];
		}
	}
}

void Clinic::readDoctorsFromFile()
{
	char* temp_array1 = new char[20];
	char* temp_array2 = new char[20];
	char* temp_array = new char[20];
	int day = 0, month = 0, year = 0, NID = 0, Age = 0, dID = 0;

	ifstream fin;
	fin.open("doctor.txt", ios::app);

	while (!(fin.eof()))
	{
		fin >> dID;
		fin >> temp_array1;
		fin >> temp_array2;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> NID;
		fin >> Age;
		fin >> temp_array;
		this->AddDoctor(temp_array1, temp_array2, day, month, year, NID, Age, dID, temp_array);
	}

	fin.close();

	delete[]temp_array1;
	delete[]temp_array2;
	delete[]temp_array;
}

void Clinic::readPatientsFromFile()
{
	char* temp_array1 = new char[20];
	char* temp_array2 = new char[20];
	int day = 0, month = 0, year = 0, NID = 0, Age = 0, pID = 0, NO = 0;

	ifstream fin;
	fin.open("patient.txt");
	while (!(fin.eof()))
	{
		fin >> pID;
		fin >> temp_array1;
		fin >> temp_array2;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> Age;
		fin >> NID;
		fin >> NO;
		this->AddPatient(temp_array1, temp_array2, day, month, year, NID, Age, pID);
	}

	delete[]temp_array1;
	delete[]temp_array2;
}

void Clinic::readRecordsFromFile()
{
	
	ifstream fin;
	fin.open("phistory.txt");

	while (!(fin.eof()))
	{
		int pID = 0, day = 0, month = 0, year = 0, hour = 0, min = 0, sec = 0, key = -1, dID = 0, temp_id = 0;
		float fee;
		char* temp_array = new char[20];

		fin >> pID;

		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			if (pID == pr_Patient_List[i][0].GetpID())
			{
				key = i;
				break;
			}
		}

		fin >> temp_array;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> hour;
		fin >> min;
		fin >> sec;
		fin >> dID;
		fin >> fee;

		mTime temp_time(hour, min, sec);
		mDate temp_date(day, month, year);

		pr_Patient_List[key][0].AddRecord(temp_array, dID, temp_date, temp_time, fee, 0);

		delete[]temp_array;
		temp_array = nullptr;
	}
}

void Clinic::readAppoinmentsFromFile()
{
	char* temp_array = new char[20];
	int pID = 0, dID = 0, day = 0, month = 0, year = 0, hour = 0, min = 0, sec = 0, token = 0;
	float fee = 0, fee_paid = 0;
	ifstream fin;
	fin.open("appointment.txt");
	while (!(fin.eof()))
	{
		fin >> temp_array;
		fin >> pID;
		fin >> dID;
		fin >> day;
		fin >> month;
		fin >> year;
		fin >> hour;
		fin >> min;
		fin >> sec;
		fin >> token;
		fin >> fee;
		fin >> fee_paid;

		this->AddAppointment(temp_array, pID, dID, day, month, year, hour, min, sec, token, fee, fee_paid);
	}
	fin.close();
}

void Clinic::readDocRecordsFromFile()
{
	int dID = 0, pID = 0, key = -1;
	ifstream fin;
	fin.open("dhistory.txt");

	while (!(fin.eof()))
	{
		fin >> dID;
		fin >> pID;

		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			if (dID == pr_Doctor_List[i][0].GetdID())
			{
				key = i;
				break;
			}
		}

		pr_Doctor_List[key][0].AddPatient_record(pID);
	}
	
}

Clinic::~Clinic()
{
	if (pr_Appointment_List != nullptr)
	{
		for (int i = 0; i < pr_NoOFAppointments; i++)
		{
			delete pr_Appointment_List[i];
		}

		delete[]pr_Appointment_List;
		pr_Appointment_List = nullptr;
	}

	if (pr_Doctor_List != nullptr)
	{
		for (int i = 0; i < pr_NoOfDoctors; i++)
		{
			delete pr_Doctor_List[i];
		}

		delete[]pr_Doctor_List;
		pr_Doctor_List = nullptr;
	}

	if (pr_Patient_List!= nullptr)
	{
		for (int i = 0; i < pr_NoOfPatients; i++)
		{
			delete pr_Patient_List[i];
		}

		delete[]pr_Patient_List;
		pr_Patient_List = nullptr;
	}
}
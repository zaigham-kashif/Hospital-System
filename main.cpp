#include<iostream>
#include"Clinic.h"
#include<string.h>

using namespace std;

int main()
{
	Clinic clinic;
	int ID = 0, option = 0;
	int day = 0, month = 0, year = 0;

	clinic.readDoctorsFromFile();
	clinic.readPatientsFromFile();
	clinic.readAppoinmentsFromFile();
	clinic.readRecordsFromFile();
	clinic.readDocRecordsFromFile();

	do
	{
		clinic.AddAllPatientsToFile();
		clinic.AddAllDoctorsToFile();
		clinic.AddAllAppointmentsToFile();
		clinic.AddAlldRecordsToFile();
		clinic.AddAllpRecordsToFile();


		if (!(option <= 1 && option >= 14))
		{
			system("CLS");
		}

		cout << "	-----------------------------------------------------------------------"<< endl;
		cout << "	Select An option from the menu Below : "<<endl;
		cout << "	***********************************************************************" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	1-> Add a Doctor                                                       |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	2-> Add a Patient                                                      |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	3-> Create An Appointment                                              |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout <<"	4-> Mark an Appointment Done                                           |" <<endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	5-> Print All the Appointments                                         |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	6-> Print All remaning Appointments of a Doctor                        | " << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	7-> Print All remaning Appointments of a Patient                       |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	8-> Print All remaning Appointments of a Day                           |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	9-> Print Visit History of a Patient                                   |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	10-> Print History of a Doctor                                         |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	11-> Delete a Doctor                                                   |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	12-> Delete a Patient                                                  |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	13-> Print Data of All Doctors                                         |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	14-> Print Data of All Patients                                        |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	15-> Print Data of All Patients visited By Same Doctor on Specific Date|" << endl;
		cout << "	_______________________________________________________________________" << endl; 
		cout << "	16-> Print Data of All Patients visited By Same Doctor                 |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	17-> Delete An Appointment                                             |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	18-> Print Data of a Doctor                                            |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	19-> Print Data of a Patient                                           |" << endl;
		cout << "	_______________________________________________________________________" << endl;
		cout << "	***********************************************************************" << endl;
		cout << "	0-> Exit The Program" << endl;
		cout << "	-----------------------------------------------------------------------" << endl;
		cout << "	-> ";
		cin >> option;
		cin.ignore();
		if (option == 1)
		{
			system("CLS");
			int key = -1;
			char* temp_array1;
			char* temp_array2;
			char* copy_array1;
			char* copy_array2;
			temp_array1 = new char[20];
			temp_array2 = new char[20];
			cout << "	Enter First Name    : ";
			cin.getline(temp_array1, 20);
			cout << "	Enter Last Name     : ";
			cin.getline(temp_array2, 20);
			int day, month, year;
			cout << "	Enter Date of Birth (Day Month Yera) : " << endl;
			cout << "	Day   : ";
			cin >> day;
			cout << "	Month : ";
			cin >> month;
			cout << "	Year  : ";
			cin >> year;
			int NID = 0, Age = 0;
			cout << "	Enter National ID # : ";
			cin >> NID;
			cout << "	Enter Age           : ";
			cin >> Age;
			int dID;
			do
			{
				key = -1;
				cout << "	Enter Doctor's ID # : ";
				cin >> dID;
				for (int i = 0; i < clinic.getNoOfDoctors(); i++)
				{
					if (dID == clinic.getDoctors()[i][0].GetdID())
					{
						key = i;
						break;
					}
				}

				if (key != -1)
				{
					cout << "	There is an other doctor with the same ID # " << endl;
					cout << "	       Please use a different ID #" << endl;
				}
			} while (key != -1);

			cin.ignore();
			char* temp_array = new char[20];
			cout << "	Enter Doctor's Specialization Field : ";
			cin.getline(temp_array, 20);
			clinic.AddDoctor(temp_array1, temp_array2, day, month, year, NID, Age, dID, temp_array);
			delete[]temp_array;
			delete[]temp_array1;
			delete[]temp_array2;
			cout << "	" << system("pause");
		}
		else if (option == 2)
		{
			system("CLS");
			int key = -1;
			char* temp_array1;
			char* temp_array2;
			temp_array1 = new char[20];
			temp_array2 = new char[20];
			cout << "	Enter First Name : ";
			cin.getline(temp_array1, 20);
			cout << "	Enter Last Name  : ";
			cin.getline(temp_array2, 20);
			int day, month, year;
			cout << "	Enter Date of Birth (Day Month Yera) : " << endl;
			cout << "	Day   : ";
			cin >> day;
			cout << "	Month : ";
			cin >> month;
			cout << "	Year  : ";
			cin >> year;
			int NID = 0, Age = 0;
			cout << "	Enter National ID # : ";
			cin >> NID;
			cout << "	Enter Age           : ";
			cin >> Age;
			int pID;
			do
			{
				key = -1;
				cout << "	Enter Patient's ID  : ";
				cin >> pID;
				for (int i = 0; i < clinic.getNoOfPatients(); i++)
				{
					if (clinic.getPatient()[i][0].GetpID() == pID)
					{
						key = i;
					}
				}

				if (key != -1)
				{
					cout << "	Patient with this ID Already Exist " << endl;
					cout << "	     Try a different ID #" << endl;
				}

			} while (key != -1);

			clinic.AddPatient(temp_array1, temp_array2, day, month, year, NID, Age, pID);

			delete[]temp_array1;
			delete[]temp_array2;

			cout << "	" << system("pause");
		}
		else if (option == 3)
		{
			system("CLS");
			int key = -1;
			int pID = 0, dID = 0, TokenNO = 0, Fee = 0, Paid_Fee = 0;
			char* Temp_array = new char[20];
			cout << "	Enter Disease Type   : ";
			cin.getline(Temp_array, 20);
			do
			{
				key = -1;
				cout << "	Enter Patient's ID # : ";
				cin >> pID;
				for (int i = 0; i < clinic.getNoOfPatients(); i++)
				{
					if (pID == clinic.getPatient()[i][0].GetpID())
					{
						key = i;
						break;
					}
				}

				if (key == -1)
				{
					cout << "	No patient with such ID exist so appointment can not be created " << endl;
					cout << "	              Double cheak the ID #" << endl;
				}
			} while (key == -1);

			do
			{
				key = -1;
				cout << "	Enter Doctor's ID #  : ";
				cin >> dID;

				for (int i = 0; i < clinic.getNoOfDoctors(); i++)
				{
					if (dID == clinic.getDoctors()[i][0].GetdID())
					{
						key = i;
						break;
					}
				}

				if (key == -1)
				{
					cout << "	No Doctor with such ID exist so appointment can not be created " << endl;
					cout << "	              Double cheak the ID #" << endl;
				}
			} while (key == -1);


			int day, month, year, hour, min, sec;
			cout << "	Enter Appointment Date (Day Month Year) : " << endl;
			cout << "	Day   : ";
			cin >> day;
			cout << "	Month : ";
			cin >> month;
			cout << "	Year  : ";
			cin >> year;
			cout << "	Enter Appoinment Time (Hours Min Sec)  :  " << endl;
			cout << "	Hours : ";
			cin >> hour;
			cout << "	Min   : ";
			cin >> min;
			cout << "	Sec   : ";
			cin >> sec;

			do
			{
				key = -1;
				cout << "	Enter Token Number   : ";
				cin >> TokenNO;
				for (int i = 0; i < clinic.getNoOfAppointments(); i++)
				{
					if (TokenNO == clinic.getAppointment()[i][0].GetTokenNo())
					{
						key = i;
					}
				}

				if (key != -1)
				{
					cout << "	Appointment with this token no already exists " << endl;
				}

			} while (key != -1);

			cout << "	Enter Total Charges  : ";
			cin >> Fee;
			cout << "	Enter Paid Charges   : ";
			cin >> Paid_Fee;

			clinic.AddAppointment(Temp_array, pID, dID, day, month, year, hour, min, sec, TokenNO, Fee, Paid_Fee);
			cout << "	" << system("pause");
			delete[]Temp_array;
		}
		else if (option == 4)
		{
			system("CLS");
			clinic.MarkAppointmentDone();
			
			cout << "	" << system("pause");
		}
		else if (option == 5)
		{
			system("CLS");
			clinic.PrintAppointmentList();
			cout << "	" << system("pause");
		}
		else if (option == 6)
		{
			system("CLS");
			cout << "	Enter Doctor's ID : ";
			cin >> ID;
			clinic.PrintAppointmentsofDoctor(ID);
			cout << "	" << system("pause");
		}
		else if (option == 7)
		{
			system("CLS");
			cout << "	Enter Patient's ID : ";
			cin >> ID;
			clinic.PrintAppointmentsofPatient(ID);
			cout << "	" << system("pause");
		}
		else if (option == 8)
		{
			system("CLS");
			cout << "	Enter Date(day month year)" << endl;
			cout << "	Day   : ";
			cin >> day;
			cout << "	Month : ";
			cin >> month;
			cout << "	Year  : ";
			cin >> year;
			clinic.PrintAppointmentsofDay(day, month, year);
			cout << "	" << system("pause");
		}
		else if (option == 9)
		{
			system("CLS");
			cout << "	Enter Patient's ID : ";
			cin >> ID;
			clinic.PatientRecordHistory(ID);
			cout << "	" << system("pause");
		}
		else if (option == 10)
		{
			system("CLS");
			cout << "	Enter Doctor's ID : ";
			cin >> ID;
			clinic.DoctorRecordHistory(ID);
			cout << "	" << system("pause");
		}
		else if (option == 11)
		{
			system("CLS");
			clinic.RemoveDoctor();
			cout << "	" << system("pause");
		}
		else if (option == 12)
		{
			system("CLS");
			clinic.RemovePatient();
			cout << "	" << system("pause");
		}
		else if (option == 13)
		{
			system("CLS");
			clinic.PrintDoctorList();
			cout << "	" << system("pause");
		}
		else if (option == 14)
		{
			system("CLS");
			clinic.PrintPatientList();
			cout << "	" << system("pause");
		}
		else if (option == 15)
		{
			system("CLS");
			cout << "	Enter Doctor's ID : ";
			cin >> ID;
			cout << "	Enter Date(day month year)" << endl;
			cout << "	Day   : ";
			cin >> day;
			cout << "	Month : ";
			cin >> month;
			cout << "	Year  : ";
			cin >> year;

			clinic.PrintPatientVisByDoc(ID, day, month, year);
			cout << "	" << system("pause");

		}
		else if (option == 16)
		{
			system("CLS");
			cout << "	Enter Doctor's ID : ";
			cin >> ID;

			clinic.PrintPVisByDoc(ID);
			cout << "	" << system("pause");
		}
		else if (option == 17)
		{
			system("CLS");
			cout << "	Enter Appointment's Token Number to be deleted : ";
			cin >> ID;
			clinic.DeleteAppointment(ID);
			cout << "	" << system("	pause");
		}
		else if (option == 18)
		{
			system("CLS");
			int key = -1;
			cout << "	Enter Doctor's ID : ";
			cin >> ID;
			for (int i = 0; i < clinic.getNoOfDoctors(); i++)
			{
				if (clinic.getDoctors()[i][0].GetdID() == ID)
				{
					key = i;
					break;
				}
			}
			if (key == -1)
			{
				cout << "	No Doctor with such ID is Present" << endl;
			}
			else
			{
				cout << "	------------------------------------------" << endl;
				cout << clinic.getDoctors()[key][0];
				cout << "	------------------------------------------" << endl;
			}
			cout << "	" << system("	pause");
		}
		else if (option == 19)
		{
			system("CLS");
			int key = -1;
			cout << "	Enter Patient's ID : ";
			cin >> ID;
			for (int i = 0; i < clinic.getNoOfPatients(); i++)
			{
				if (clinic.getPatient()[i]->GetpID() == ID)
				{
					key = i;
					break;
				}
			}
			if (key == -1)
			{
				cout << "	No Patient with such ID is Present" << endl;
			}
			else
			{
				cout << "	------------------------------------------" << endl;
				cout << clinic.getPatient()[key][0];
				cout << "	------------------------------------------" << endl;
			}
			cout << "	" << system("	pause");
		}
		else if (option != 0)
		{
			system("CLS");
			cout << "	***Invalid Option Selected***" << endl;
			cout << endl;
			cout << endl;
		}

	} while (option < 0 || option>0);
}

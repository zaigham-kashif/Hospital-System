#pragma once
#include"Doctor.h"
#include"Patient.h"
#include"Appointment.h"

class Clinic
{
	private:
		int pr_NoOfDoctors;
		Doctor** pr_Doctor_List;
		int pr_NoOfPatients;
		Patient** pr_Patient_List;
		int pr_NoOFAppointments;
		Appointment** pr_Appointment_List;

	public:
		Clinic();

		int getNoOfDoctors();
		int getNoOfPatients();
		int getNoOfAppointments();
		Doctor** getDoctors();
		Patient** getPatient();
		Appointment** getAppointment();

		void AddDoctor(const char*, const char*, int, int, int, int, int, int, const char*);
		void AddPatient(const char*, const char*, int, int, int, int, int, int);
		void AddAppointment(const char*, int, int, int, int, int, int, int, int, int, float, float);

		void RemoveDoctor();
		void RemovePatient();
		void DeleteAppointment(int);

		void PrintDoctorList();
		void PrintPatientList();
		void PrintAppointmentList();

		void MarkAppointmentDone();
		void PrintPendingAppointments();
		void PrintAppointmentsofDoctor(int);
		void PrintAppointmentsofPatient(int);
		void PrintAppointmentsofDay(int, int, int);
		void PrintPatientVisByDoc(int, int, int, int);
		void PrintPVisByDoc(int);
		void PatientRecordHistory(int);
		void DoctorRecordHistory(int);

		void AddDoctorToFile(const char*, const char*, int, int, int, int, int, int, const char*);
		void AddPatientToFile(const char*, const char*, int, int, int, int, int, int);

		void AddAllDoctorsToFile();
		void AddAllPatientsToFile();
		void AddAllAppointmentsToFile();
		void AddAllpRecordsToFile();
		void AddAlldRecordsToFile();

		void readDoctorsFromFile();
		void readPatientsFromFile();
		void readRecordsFromFile();
		void readAppoinmentsFromFile();
		void readDocRecordsFromFile();

		~Clinic();
};


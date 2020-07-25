#pragma once
#include"mDate.h"
#include"Name.h"
#include<iostream>

using namespace std;

class Person 
{
	private:
		Name pr_pName;
		mDate pr_DOB;
		int pr_age;
		int pr_Nid;
	public:
		Person();
		Person(int, int, int, int, int, const char*, const char*);
		Person(Person&);


		void SetAge(int);
		void SetNid(int);
		void SetDOB(int ,int,int);
		void SetpName(const char*, const char*);
		void AddData();
		void AddData(int, int, int, int, int, const char*, const char*);

		int GetAge();
		int GetNid();
		mDate GetDOB();
		Name GetName();

		friend ostream& operator<<(ostream&, Person&);
};


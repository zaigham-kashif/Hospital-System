#pragma once
#include<iostream>

using namespace std;

class Name
{
	private:
		char* pr_fname;
		char* pr_lname;
	public:
		Name();
		Name(const char*,const char*);
		Name(Name&);

		void Set_person_name(const char*,const char*);
		void Set_fname(const char*);
		void Set_lname(const char*);
		void CopyName(Name&);

		const char* Get_fname();
		const char* Get_lname();

		friend ostream & operator <<(ostream&, Name&);

		~Name();

};


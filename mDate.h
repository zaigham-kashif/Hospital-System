#pragma once
#include<iostream>

using namespace std;

class mDate
{
	private:
		int pr_day;
		int pr_month;
		int pr_year;
	public:
		mDate();
		mDate(int, int, int);
		mDate(mDate&);

		void SetDate(int, int, int);
		void SetDay(int);
		void SetMonth(int);
		void SetYear(int);
		void CopyDate(mDate&);

		int GetDay();
		int GetMonth();
		int GetYear();

		friend ostream& operator<<(ostream&, mDate&);


};


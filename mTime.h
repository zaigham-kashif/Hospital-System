#pragma once
#include<iostream>

using namespace std;

class mTime
{
	private:
		int pr_hour;
		int pr_min;
		int pr_sec;
	public:
		mTime();
		mTime(int, int, int);
		mTime(mTime&);

		void SetTime(int, int, int);
		void SetHour(int);
		void SetMin(int);
		void SetSec(int);
		void CopyTime(mTime&);

		int GetHour();
		int GetMin();
		int GetSec();

		friend ostream& operator <<(ostream&, mTime&);

};


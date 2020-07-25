#include "mTime.h"

mTime::mTime()
{
	pr_hour = 0;
	pr_min = 0;
	pr_sec = 0;
}

mTime::mTime(int hour, int min, int sec)
{
	pr_hour = hour;
	pr_min = min;
	pr_sec = sec;
}

mTime::mTime(mTime& obj_in)
{
	pr_hour = obj_in.pr_hour;
	pr_min = obj_in.pr_min;
	pr_sec = obj_in.pr_sec;
}

void mTime::SetTime(int hour, int min, int sec)
{
	pr_hour = hour;
	pr_min = min;
	pr_sec = sec;
}

void mTime::SetHour(int hours)
{
	pr_hour = hours;
}

void mTime::SetMin(int min)
{
	pr_min = min;
}

void mTime::SetSec(int sec)
{
	pr_sec = sec;
}

void mTime::CopyTime(mTime& obj_in)
{
	pr_hour = obj_in.pr_hour;
	pr_min = obj_in.pr_min;
	pr_sec = obj_in.pr_sec;
}

int mTime::GetHour()
{
	return pr_hour;
}

int mTime::GetMin()
{
	return pr_min;
}

int mTime::GetSec()
{
	return pr_sec;
}

ostream& operator<<(ostream& out, mTime& obj_in)
{
	out << obj_in.pr_hour << ":" << obj_in.pr_min << ":" << obj_in.pr_sec;
	return out;
}

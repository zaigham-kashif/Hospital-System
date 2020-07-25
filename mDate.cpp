#include "mDate.h"

mDate::mDate()
{
	pr_day = 0;
	pr_month = 0;
	pr_year = 0;
}

mDate::mDate(int day, int month, int year)
{
	pr_day = day;
	pr_month = month;
	pr_year = year;
}

mDate::mDate(mDate& obj_in)
{
	pr_day = obj_in.pr_day;
	pr_month = obj_in.pr_month;
	pr_year = obj_in.pr_year;
}

void mDate::SetDate(int day, int month, int year)
{
	pr_day = day;
	pr_month = month;
	pr_year = year;
}

void mDate::SetDay(int day)
{
	pr_day = day;
}

void mDate::SetMonth(int month)
{
	pr_month = month;
}

void mDate::SetYear(int year)
{
	pr_year = year;
}

void mDate::CopyDate(mDate& obj_in)
{
	pr_day = obj_in.pr_day;
	pr_month = obj_in.pr_month;
	pr_year = obj_in.pr_year;
}

int mDate::GetDay()
{
	return pr_day;
}

int mDate::GetMonth()
{
	return pr_month;
}

int mDate::GetYear()
{
	return pr_year;
}

ostream& operator<<(ostream& out, mDate& obj_in)
{
	out << obj_in.pr_day << "/" << obj_in.pr_month << "/" << obj_in.pr_year;
	return out;
}

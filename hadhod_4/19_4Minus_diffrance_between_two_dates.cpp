#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

using namespace std;
struct sDate
{
	short day = 0;
	short month = 0;
	short year = 0;
};
int diffrance_between_two_dates(sDate date1, sDate date2, bool include_end_day = 0);
sDate Get_ystem_daate();
int main()
{
	sDate Date1, Date2;
	Date1.day = 1;
	Date1.month = 1;
	Date1.year = 2020;

	Date2.day = 1;
	Date2.month = 1;
	Date2.year = 2015;

	cout << diffrance_between_two_dates(Date1, Date2);




}
sDate Get_ystem_daate()
{
	time_t t = time(0);
	tm now = {};
	localtime_s(&now, &t);
	sDate SystemDate;
	SystemDate.day = now.tm_mday;
	SystemDate.month = now.tm_mon + 1; // tm_mon is 0-based
	SystemDate.year = now.tm_year + 1900; // tm_year is years since 1900
	return SystemDate;
}

bool Is_leap_year(short year)
{
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short month_days_of_year(short month, short year)
{
	if (month < 1 || month>12)
		return 0;
	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((month == 2) ? ((Is_leap_year(year) ? 29 : 28)) : month_arr[month]);
}

bool Is_Last_day_in_month(sDate date)
{
	short month_day = month_days_of_year(date.month, date.year);
	return (date.day == month_day);
}

bool Is_Last_month_in_year(sDate date)
{
	return (date.month == 12);
}

sDate Increas_date_by_one(sDate date)
{
	if (Is_Last_day_in_month(date))
	{
		if (Is_Last_month_in_year(date))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.day = 1;
			date.month++;
		}
	}
	else
		date.day++;
	return date;
}

bool Is_Date1_Befor_Date2(sDate date1, sDate date2)
{
	if (date1.year < date2.year)
		return true;
	if (date1.year == date2.year)
	{
		if (date1.month < date2.month)
			return true;
		if (date1.month == date2.month)
			if (date1.day < date2.day)
				return true;
	}
	return false;
}

int diffrance_between_two_dates(sDate date1, sDate date2, bool include_end_day)
{
	int deffrance = 0;
	short flag_swap = 1;
	if (Is_Date1_Befor_Date2(date2, date1))
	{
		swap(date1, date2);
		flag_swap = -1;
	}

	while (Is_Date1_Befor_Date2(date1, date2))
	{
		date1 = Increas_date_by_one(date1);
		deffrance++;
	}
	return(include_end_day ? ++deffrance * flag_swap : deffrance * flag_swap);
}
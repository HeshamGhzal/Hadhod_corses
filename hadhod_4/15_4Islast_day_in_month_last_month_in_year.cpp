#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
struct sDate
{
	short day = 0;
	short month = 0;
	short year = 0;
};
bool  Is_Last_day_in_month(sDate date);
bool Is_Last_month_in_year(sDate date);

int main()
{
	sDate Date1, Date2;
	Date1.day = 29;
	Date1.month = 12;
	Date1.year = 2000;

	cout << Is_Last_day_in_month(Date1) << endl;
	cout << Is_Last_month_in_year(Date1);



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

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
short days_from_begining_of_year(short day, short month, short year);

int main()
{
	short day = 31;
	short month = 12;
	short year = 1972;

	cout << days_from_begining_of_year(day, month, year);



}

bool Is_leap_year(short year)
{
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
short day_Order_from_Gregorian_calender(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;

	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}
short month_days_of_year(short year, short month)
{
	if (month < 1 || month>12)
		return 0;
	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((month == 2) ? ((Is_leap_year(year) ? 29 : 28)) : month_arr[month]);
}

//short days_from_begining_of_year(short day, short month, short year)
//{
//	short sum_days = 0;
//	short month_reminer = month_days_of_year(year, month) - day;
//	for (short i = 1; i <= month; i++)
//	{
//		for (short j = 0; j < month_days_of_year(year, i); j++)
//		{
//			sum_days++;
//		}
//	}
//	return sum_days - month_reminer;
//}
short days_from_begining_of_year(short day, short month, short year)
{
	short total_days = 0;
	for (short i = 1; i <= month - 1; i++)
	{
		total_days += month_days_of_year(year, i);
	}
	return total_days + day;
}
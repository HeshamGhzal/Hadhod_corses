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
sDate add_dsys_to_date(short days, sDate Date);


int main()
{
	sDate Date;
	Date.day = 10;
	Date.month = 10;
	Date.year = 2022;

	Date = add_dsys_to_date(2500, Date);




	cout << "\n" << Date.day << "/" << Date.month << "/" << Date.year << endl;


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
short month_days_of_year(short month, short year)
{
	if (month < 1 || month>12)
		return 0;
	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((month == 2) ? ((Is_leap_year(year) ? 29 : 28)) : month_arr[month]);
}

//short days_from_begining_of_year(short day, short month, short year)
//{
//	short sum_days = 0;
//	short month_reminder = month_days_of_year(year, month) - day;
//	for (short i = 1; i <= month; i++)
//	{
//		for (short j = 0; j < month_days_of_year(year, i); j++)
//		{
//			sum_days++;
//		}
//	}
//	return sum_days - month_reminder;
//}
short days_from_begining_of_year(short day, short month, short year)
{
	short total_days = 0;
	for (short i = 1; i <= month - 1; i++)
	{
		total_days += month_days_of_year(i, year);
	}
	return total_days + day;
}
sDate convert_days_of_year_to_dat(short days, short year)
{
	sDate date;
	if (days < 1 || days >(Is_leap_year(year) ? 366 : 365))
		return date;
	date.year = year;
	date.month = 1;
	while (days > month_days_of_year(date.month, year))
	{
		days -= month_days_of_year(date.month, year);
		date.month++;
	}
	date.day = days;
	return date;
}

//sDate add_dsys_to_date(short days, sDate date)
//{
//	date.day += days;
//	while (date.day > month_days_of_year(date.month, date.year))
//	{
//		date.day -= month_days_of_year(date.month, date.year);
//		date.month++;                        //for test(input [days 2500]  day10 / moth 10 / year2022 )
//		if (date.month > 12)              //(output 14 /8/2029)
//		{
//			date.month = 1;
//			date.year++;
//		}
//	}
//	return date;
//}

sDate add_dsys_to_date(short days, sDate date)
{
	date.day = days_from_begining_of_year(date.day, date.month, date.year) + days;
	date.month = 1;
	while (date.day > month_days_of_year(date.month, date.year))
	{
		date.day -= month_days_of_year(date.month, date.year);
		date.month++;                       //for test(input [days 2500]  day10 / moth 10 / year2022 )
		if (date.month > 12)                        //(output 14 /8/2029)
		{
			date.month = 1;
			date.year++;
		}
	}
	return date;
}


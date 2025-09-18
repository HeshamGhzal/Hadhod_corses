#include<iostream>
#include<string>
#include<ctime>

using namespace std;
struct sDate
{
	short day = 0;
	short month = 0;
	short year = 0;
};

string Day_Name(sDate date);

short compare_two_dates(sDate date1, sDate date2);



int main()
{
	sDate Date1, Date2;
	Date1.day = 1;
	Date1.month = 2;
	Date1.year = 2022;

	Date2.day = 2;
	Date2.month = 2;
	Date2.year = 2022;



	cout << compare_two_dates(Date1, Date2);




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

short day_Order_from_Gregorian_calender_overloded(sDate date)
{

	return day_Order_from_Gregorian_calender(date.day, date.month, date.year);
}

string Weekday_Name(short day_index)
{
	string day_arr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return day_arr[day_index];
}

string Day_Name(sDate date)
{
	short Day_indx = day_Order_from_Gregorian_calender_overloded(date);
	string day_name = Weekday_Name(Day_indx);
	return day_name;
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

bool Is_End_of_week(sDate date)
{
	short Day_order = day_Order_from_Gregorian_calender_overloded(date);
	return(Day_order == 6);
}

bool Is_WeekEnd(sDate date)
{
	short Day_order = day_Order_from_Gregorian_calender_overloded(date);
	return(Day_order == 5 || Day_order == 6);
}

bool Is_Business_Day(sDate date)
{
	return (!Is_WeekEnd(date));
}

bool Is_Date1_Equal_Date2(sDate date1, sDate date2)
{
	if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
		return true;
	return false;
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

bool Is_Date1_After_Date2(sDate date1, sDate date2)
{
	return(!(Is_Date1_Befor_Date2(date1, date2)) && !(Is_Date1_Equal_Date2(date1, date2)));
}

short compare_two_dates(sDate date1, sDate date2)
{
	if (Is_Date1_Befor_Date2(date1, date2))
		return -1;
	else if (Is_Date1_After_Date2(date1, date2))
		return 1;
	else
		return 0;
}


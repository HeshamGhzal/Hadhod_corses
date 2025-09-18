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
sDate Decreas_date_by_one(sDate date);
sDate Decreas_date_by_x_days(int xdays, sDate date);
sDate Decreas_date_by_one_week(sDate date);
sDate Decreas_date_by_x_weeks(int xweeks, sDate date);
sDate Decreas_date_by_one_month(sDate date);
sDate Decreas_date_by_x_months(int xmonths, sDate date);
sDate Decreas_date_by_one_year(sDate date);
sDate Decreas_date_by_x_year(int xyear, sDate date);
sDate Decreas_date_by_x_year_faster(int xyear, sDate date);
sDate Decreas_date_by_one_decade(sDate date);
sDate Decreas_date_by_x_decades(int xdecades, sDate date);
sDate Decreas_date_by_x_decades_faster(int xdecades, sDate date);
sDate Decreas_date_by_one_century(sDate date);
sDate Decreas_date_by_one_Milleium(sDate date);
int main()
{
	sDate Date1, Date2;
	Date1.day = 1;
	Date1.month = 1;
	Date1.year = 2023;



	cout << "Date                          : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one(Date1);
	cout << "Date before one day            : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_days(10, Date1);
	cout << "Date before [10] days          : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_week(Date1);
	cout << "Date before one_week           : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_weeks(10, Date1);
	cout << "Date before [10] weeks         : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_month(Date1);
	cout << "Date before one month          : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_months(5, Date1);
	cout << "Date before [5] months         : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_year(Date1);
	cout << "Date before one year           : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_year(10, Date1);
	cout << "Date before [10] year          : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_year_faster(10, Date1);
	cout << "Date before [10] year faster   : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_decade(Date1);
	cout << "Date before one decade         : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_decades(10, Date1);
	cout << "Date before [10] decade        : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_x_decades_faster(10, Date1);
	cout << "Date before [10] decade faster : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_century(Date1);
	cout << "Date before one century        : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;
	Date1 = Decreas_date_by_one_Milleium(Date1);
	cout << "Date before one _Milleium      : " << Date1.day << "/" << Date1.month << "/" << Date1.year << endl;


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

sDate Decreas_date_by_one(sDate date)
{
	if (date.day == 1)
	{
		if (date.month == 1)
		{
			date.day = month_days_of_year(date.month, date.year);
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month--;
			date.day = month_days_of_year(date.month, date.year);

		}
	}
	else
		date.day--;
	return date;
}

sDate Decreas_date_by_x_days(int xdays, sDate date)
{
	for (int i = 0; i < xdays; i++)
	{
		date = Decreas_date_by_one(date);
	}
	return date;
}

sDate Decreas_date_by_one_week(sDate date)
{
	for (int i = 0; i < 7; i++)
	{
		date = Decreas_date_by_one(date);
	}
	return date;
}

sDate Decreas_date_by_x_weeks(int xweeks, sDate date)
{
	for (int i = 0; i < xweeks; i++)
	{
		date = Decreas_date_by_one_week(date);
	}
	return date;
}

sDate Decreas_date_by_one_month(sDate date)
{
	if (date.month == 1)
	{
		date.month = 12;
		date.year--;
	}
	else
	{
		date.month--;
	}
	if (date.day > month_days_of_year(date.month, date.year))
	{
		date.day = month_days_of_year(date.month, date.year);
	}
	return date;
}

sDate Decreas_date_by_x_months(int xmonths, sDate date)
{
	for (int i = 0; i < xmonths; i++)
	{
		date = Decreas_date_by_one_month(date);
	}
	return date;
}

sDate Decreas_date_by_one_year(sDate date)
{
	date.year--;
	return date;
}

sDate Decreas_date_by_x_year(int xyear, sDate date)
{
	for (int i = 0; i < xyear; i++)
	{
		date = Decreas_date_by_one_year(date);
	}
	return date;
}

sDate Decreas_date_by_x_year_faster(int xyear, sDate date)
{
	date.year -= xyear;
	return date;
}

sDate Decreas_date_by_one_decade(sDate date)
{
	date.year -= 10;
	return date;
}

sDate Decreas_date_by_x_decades(int xdecades, sDate date)
{
	for (int i = 0; i < xdecades; i++)
	{
		date = Decreas_date_by_one_decade(date);
	}
	return date;
}

sDate Decreas_date_by_x_decades_faster(int xdecades, sDate date)
{
	date.year -= (xdecades * 10);
	return date;
}

sDate Decreas_date_by_one_century(sDate date)
{
	date.year -= 100;
	return date;
}

sDate Decreas_date_by_one_Milleium(sDate date)
{
	date.year -= 1000;
	return date;
}

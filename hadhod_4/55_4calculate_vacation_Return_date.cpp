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

bool Is_Date1_After_Date2(sDate date1, sDate date2);



int main()
{
	sDate Date1, Date2;
	Date1.day = 2;
	Date1.month = 2;
	Date1.year = 2022;

	Date2.day = 1;
	Date2.month = 2;
	Date2.year = 2022;



	cout << Is_Date1_After_Date2(Date1, Date2);




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

short Days_until_weekEnd(sDate date)
{
	short day_index = day_Order_from_Gregorian_calender_overloded(date);
	short days = 0;
	for (short i = day_index; i < 5; i++)
	{
		days++;
	}
	return days;
}

short Days_until_end_of_week(sDate date)
{
	short day_index = day_Order_from_Gregorian_calender_overloded(date);
	return (6 - day_index);
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

short Days_until_end_of_month(sDate date)
{
	sDate date2;

	date2.day = month_days_of_year(date.month, date.year);
	date2.month = date.month;
	date2.year = date.year;
	short days = diffrance_between_two_dates(date, date2, 1);
	return days;
}

short Days_until_end_of_year(sDate date)
{
	sDate date2;

	date2.day = 31;
	date2.month = 12;
	date2.year = date.year;
	short days = diffrance_between_two_dates(date, date2, 1);
	return days;
}

//short calculate_vacation(sDate from, sDate to)
//{
//	int main_periot = diffrance_between_two_dates(from, to, 0);
//	int Actual_vacation = 0;
//	for (int i = 0; i < main_periot; i++)
//	{
//		if (Is_Business_Day(from))
//		{
//			Actual_vacation++;
//		}
//		from = Increas_date_by_one(from);
//	}
//	return Actual_vacation;
//}

short calculate_vacation(sDate from, sDate to)
{
	int Actual_vacation = 0;
	while (Is_Date1_Befor_Date2(from, to))
	{
		if (Is_Business_Day(from))
		{
			Actual_vacation++;
		}
		from = Increas_date_by_one(from);
	}
	return Actual_vacation;
}


sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
{
	//Hadhod solving
	// -------------
	short WeekEndCounter = 0;
	//in case the data  is weekend keep adding one day util you reach business day
//we get rid of all weekends before the first business day
	while (Is_WeekEnd(DateFrom))
	{
		DateFrom = Increas_date_by_one(DateFrom);
	}

	//here we increase the vacation dates to add all weekends to it.

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (Is_WeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = Increas_date_by_one(DateFrom);
	}

	//in case the return date is week end keep adding one day util you reach business day
	while (Is_WeekEnd(DateFrom))
	{
		DateFrom = Increas_date_by_one(DateFrom);
	}

	return DateFrom;
}




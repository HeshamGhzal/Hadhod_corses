#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void Month_Calender(short month, short year);
void Year_Calender(short year);
int main()
{
	short day = 9;
	short month = 9;
	short year = 1972;



	cout << "\n";
	//Month_Calender(month, year);
	Year_Calender(year);
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
string Weekday_Name(short day_index)
{
	string day_arr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return day_arr[day_index];
}
void show_Weekday()
{
	string day_arr[] = { "Sun","Mon","Tues","Wed","Thur","Fri","Sat" };
	for (string day : day_arr)
		cout << setw(5) << day;
}
string month_of_year(short month_nunber)
{
	if (month_nunber < 1 || month_nunber>12)return "Month Error";
	string month_arr[] = { "","January","February","March","April","May","June"
		,"July","August","September","October","November","December" };
	return month_arr[month_nunber];
}
void Month_Calender(short month, short year)
{
	short day_index = day_Order_from_Gregorian_calender(1, month, year);
	short monthday = month_days_of_year(year, month);
	short count = day_index;
	cout << "\n------------" << month_of_year(month) << "--------------\n";
	show_Weekday();
	cout << "\n";
	for (short j = 0; j < day_index; j++)
	{
		cout << "     ";
	}
	for (short i = 0; i < monthday; i++)
	{

		if (count++ % 7 == 0 && count != 0)
		{
			cout << "\n";
		}
		//printf("%5d", i + 1);
		//printf(" %02d  ", i + 1);
		cout << setw(5) << i + 1;
		//count++;
	}
	cout << "\n" << string(35, '-') << endl;
}
void Year_Calender(short year)
{
	cout << string(35, '-');
	cout << "\n----------" << "Calender-" << year << "------------\n";
	cout << string(35, '-') << endl;
	for (short i = 1; i < 13; i++)
		Month_Calender(i, year);
}
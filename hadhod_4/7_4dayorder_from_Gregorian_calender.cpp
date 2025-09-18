#include<iostream>
using namespace std;
short day_Order_from_Gregorian_calender(short day, short month, short year);
string Weekday_Name(short day_index);
int main()
{
	short day = 11;
	short month = 4;
	short year = 1972;
	short day_index = day_Order_from_Gregorian_calender(day, month, year);
	cout << day_index << endl;
	cout << Weekday_Name(day_index) << endl;

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
string Weekday_Name(short day_index)
{
	string day_arr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return day_arr[day_index];
}
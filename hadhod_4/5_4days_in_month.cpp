#include<iostream>
#include<vector>
using namespace std;
short month_days_of_year(short year, short month);

int main()
{
	short year = 1971;
	short month = 4;
	cout << "Days in month (" << month << ") at year = [" << year << "] "
		<< month_days_of_year(year, month) << " Days" << endl;

}

bool Is_leap_year(short year)
{
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

//short month_days_of_year(short year, short month)
//{
//	if (month < 1 || month>12)
//		return 0;
//	short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (Is_leap_year(year))
//	{
//		month_arr[2] = 29;
//	}
//	return month_arr[month];
//}
short month_days_of_year(short year, short month)
{
	if (month < 1 || month>12)
		return 0;
	if (month == 2)
		return((Is_leap_year(year) ? 29 : 28));
	short month_arr[] = { 1,3,5,7,8,10,12 };
	for (short i : month_arr)
	{
		if (month == i)
			return 31;
	}
	return 30;
}
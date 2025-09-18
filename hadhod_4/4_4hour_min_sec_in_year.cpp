#include<iostream>
#include<vector>
using namespace std;
int Days_in_year(short year);
int Hours_in_year(short year);
long Minutes_in_year(short year);
long Seconds_in_year(short year);
int main()
{
	short year = 1875;
	cout << "Days    in year  = [" << year << "] " << Days_in_year(year) << " Days" << endl;
	cout << "Hours   in year  = [" << year << "] " << Hours_in_year(year) << " Hours" << endl;
	cout << "Minutes in year  = [" << year << "] " << Minutes_in_year(year) << " Minutes" << endl;
	cout << "Seconds in year  = [" << year << "] " << Seconds_in_year(year) << " Seconds" << endl;

}

bool Is_leap_year(short year)
{
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int Days_in_year(short year)
{
	return (Is_leap_year(year) ? 366 : 365);
}
int Hours_in_year(short year)
{
	return Days_in_year(year) * 24;
}
long Minutes_in_year(short year)
{
	return Days_in_year(year) * 24 * 60;
}
long Seconds_in_year(short year)
{
	return Days_in_year(year) * 24 * 60 * 60;
}
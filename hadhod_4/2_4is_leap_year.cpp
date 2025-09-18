#include<iostream>
#include<vector>
using namespace std;

bool Is_leap_year(short year);
int main()
{
	short year = 1876;
	cout << Is_leap_year(year);

}
//bool Is_leap_year(short year)
//{
//	if (year % 400 == 0)
//		return true;
//	else if (year % 4 == 0 && year % 100 != 0)
//		return true;
//	else
//		return false;
//}
// 
//bool Is_leap_year(short year)
//{
//	return (year % 400 == 0 ? true : ((year % 4 == 0 && year % 100 != 0) ? true : false));
//}

bool Is_leap_year(short year)
{
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
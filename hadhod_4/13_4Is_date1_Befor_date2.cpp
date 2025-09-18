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
bool Is_Date1_Befor_Date2(sDate date1, sDate date2);

int main()
{
	sDate Date1, Date2;
	Date1.day = 10;
	Date1.month = 11;
	Date1.year = 2022;

	Date2.day = 15;
	Date2.month = 12;
	Date2.year = 2022;

	if (Is_Date1_Befor_Date2(Date1, Date2))
		cout << "yes date1 is less than date2";
	else
		cout << "NO date1 is NOT less than date2";

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


#include<iostream>
#include<vector>
using namespace std;

string Number_to_txt(int n);


int main()
{
	int n = 950000;
	cout << Number_to_txt(n);

}

string Number_to_txt_1to19(short n)
{
	const string arr[] = { "","one","two","three","four","five","six","seven","eight"
		,"nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
		"seventeen","eighteen","nineteen" };
	if (n < 0 || n >= 20)
		return "";
	return arr[n];
}
string Number_to_txt_20to99(short n)
{
	const string arr2[] = { "","","twenty","thirty","forty","fifty","sixty",
	"seventy","eighty","ninety" };
	if (n < 20 || n >= 100)
		return "";
	return arr2[n / 10];
}
string Number_to_txt(int n)
{
	if (n == 0)
		return "Zero";
	if (n < 20)
		return Number_to_txt_1to19(n);
	if (n < 100)
	{
		string tens = Number_to_txt_20to99(n);
		string units = Number_to_txt_1to19(n % 10);
		if (units.empty())
			return tens;
		else
			return tens + " " + units;
	}
	if (n < 1000)
	{
		string hundreds = Number_to_txt(n / 100) + " hundred";
		string remainder = Number_to_txt(n % 100);
		if (n % 100 == 0)
			return hundreds;
		else
			return hundreds + " and " + remainder;
	}
	if (n < 1000000)
	{
		string thousands = Number_to_txt(n / 1000) + " thousand";
		string remainder = Number_to_txt(n % 1000);
		if (n % 1000 == 0)
			return thousands;
		else
			return thousands + " " + remainder;
	}
	if (n < 1000000000)
	{
		string millions = Number_to_txt(n / 1000000) + " million";
		string remainder = Number_to_txt(n % 1000000);
		if (n % 1000000 == 0)
			return millions;
		else
			return millions + " " + remainder;
	}
	else
		return "This Number out of range .";

}
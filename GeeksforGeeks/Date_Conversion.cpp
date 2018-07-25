#include<iostream>
#include<vector>
using namespace std;

int months[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int leap[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
long long int start = 2018843;
int mayan[] = {144000, 7200, 360, 20, 1};

string toDate(int n)
{
	string date = "";

	int years = n/365;
	int leap_years = (years/4)+1;

	int remain;

	if(years % 4)
	{
		remain = n % 365;
		remain = remain - leap_years;
	}
	else
	{
		remain = n % 365;
		remain = remain - leap_years + 1;
	}

	cout << years << " " << leap_years << " " << remain << endl;

	if(remain < 0)
	{
		years--;
		if(years % 4)
			remain = 367 + remain;
		else
			remain = 367 + remain;
	}

	if(remain == 0)
	{
		return "01-01-"+to_string(2000+years);
	}

	if(remain < 31)
	{
		if(remain <= 9)
			return "0"+to_string(remain+1)+"-01-"+to_string(2000+years);	
		return to_string(remain+1)+"-01-"+to_string(2000+years);
	}

	cout << years << " " << leap_years << " " << remain << endl;

	if(years % 4)
	{ 
		for(int i=1;i<=12;i++)
		{
			if(remain <= months[i])
			{
				int days = months[i] % remain;
				days = months[i] - months[i-1] - days+1;

				if(days <= 9)
				{
					date = "0"+to_string(days)+"-";
				}
				else
				{
					date = to_string(days)+"-";
				}

				if(i <= 9)
				{
					date += "0"+to_string(i)+"-";
				}
				else
					date += to_string(i)+"-";

				date += to_string(2000+years);

				return date;
			}
		}
	}

	for(int i=1;i<=12;i++)
	{
		if(remain <= leap[i])
		{
			int days = leap[i] % remain;
			days = leap[i] - leap[i-1] - days;

			if(days <= 9)
			{
				date = "0"+to_string(days) + "-";
			}
			else
			{
				date = to_string(days)+"-";
			}

			if(i <= 9)
			{
				date += "0"+to_string(i)+"-";
			}
			else
				date += to_string(i)+"-";

			date += to_string(2000+years);

			return date;
		}
	}

	if(remain <= 9)
		return "0"+to_string(remain+1)+"-01-"+to_string(2000+years);	
	return to_string(remain+1)+"-01-"+to_string(2000+years);
}

string getDate(string str)
{
	long long int date = 0, first = 0;

	int index = 0, size = str.size();
	for(int i=0;i<size;i++)
	{
		if(str[i] == '.')
		{
			date += mayan[index++] * stoul(str.substr(first, i-first));
			first = i+1;
		}
	}

	date+= mayan[index] * stoul(str.substr(first, size-first)); 

	int difference = date - start;
	cout << difference << endl;

	return toDate(difference);
}

int main()
{
	/*string str;
	cin >> str;
	cout << getDate(str) << endl;*/
	
	int n;
	cin >> n;

	cout << toDate(n) << endl;

	return 0;
}
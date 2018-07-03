/*
	Given a string, print and count all substring of length>=2 where the string is in
	sorted order. Example of sorted is : abc, bcde

	Example : abcbd
	output: ab
			abc
			bc
			bd
	Total are: 4
*/

#include <iostream>

using namespace std;

void print(string str, int i, int n)
{
	while(i <= n)
		cout << str[i++];
	cout << endl;
}

bool isSorted(string str, int i, int n)
{
	char last = str[i];
	while(i <= n)
	{
		if(last <= str[i])
			last = str[i];
		else
			return false;

		i ++;
	}
	return true;
}

void all_substring(string str)
{
	int count = 0;
	int size = str.size();
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
         {
         	if(j-i >= 1 && isSorted(str, i, j))
         	{
            	print(str, i, j);
            	count ++;
         	}
         }
	}

	cout << "Total are: " << count << endl;
}

int main()
{
	string str;
	cin >> str;

	all_substring(str);
	return 0;
}

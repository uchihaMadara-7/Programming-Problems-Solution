/*
	--- Question Statment ---

	The count and say sequence is the sequence of integers beginning as follows:
	1, 11, 21, 1211, 111221, ...
	1 is read off as one 1 or 11
	11 is read off as two 1 or 21
	21 is read off as one 2 and one 1 or 1211

	Given an integer n, generate the nth sequence
	Example: n = 2, output: 11
*/

#include <iostream>

using namespace std;

string nextSequence(string str)
{
	str += ' ';
	int size = str.size();
	string next = "";

	int count = 1;
	for(int i=1;i<size;i++)
	{
		if(str[i] != str[i-1])
		{
			next += to_string(count) + str[i-1];
			count = 1;
		}
		else
			count ++;
	}

	return next;
}

string countAndSay(int n)
{
	string initial = "1";
	for(int i=1;i<n;i++)
	{
		initial = nextSequence(initial);
	}

	return initial;
}

int main()
{
	int n;
	cin >> n;

	cout << countAndSay(n) << endl;
	return 0;
}

/*
	--- Question Statement ---

	Write a program to print the following pattern for given n,
	Example : n = 7
	output: 
			28 27 26 25 24 23 22
			21 20 19 18 17 16
			15 14 13 12 11
			10 9 8 7
			6 5 4
			3 2
			1
*/

#include <iostream>

using namespace std;

void printLine(int start, int finish)
{
	while(start > finish)
	{
		cout << start-- << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	int sum = n * (n+1) / 2;
	while(n > 0)
	{
		printLine(sum, sum-n);
		sum -= n;
		n --;
	}
}
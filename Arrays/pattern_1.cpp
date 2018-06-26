/*
	--- Question Statement ---
	
	Write a program to print the following pattern for given n.
	n = 5
	0 0 0 0 0
	1 0 0 0 1
	1 1 0 1 1
	1 1 1 1 1
	1 1 0 1 1
	1 0 0 0 1
	0 0 0 0 0 
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for(int i=1;i < n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j < i)
				cout << "1";
			else if(j > n-i+1)
				cout << "1";
			else
				cout << "0";
		}
		cout << endl;
	}

	for(int i=n-2;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(j < i)
				cout << "1";
			else if(j > n-i+1)
				cout << "1";
			else
				cout << "0";
		}
		cout << endl;
	}

	return 0;
}

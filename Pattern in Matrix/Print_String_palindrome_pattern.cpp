/*
	Given n, print the following pattern:
	for n = 4
	output: ABCDCBA
			 BCDCB
			  CDC
			   D
*/

#include <iostream>

using namespace std;

void printLine(int n, int s)
{
	for(int i=0;i<s;i++)
		cout << " ";

	for(int i=s;i<n;i++)
		cout << char(i+'A');

	for(int i=n-2;i>=s;i--)
		cout << char(i+'A');
    cout << endl;
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
        printLine(n, i);

	return 0;
}

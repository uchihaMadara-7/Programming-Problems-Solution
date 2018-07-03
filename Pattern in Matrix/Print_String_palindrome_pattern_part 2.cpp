/*
	Given n, print the following pattern:
	for n = 6
	output: ABCDEFEDCBA
			ABCDE EDCBA
			ABCD   DCBA
			ABC     CBA
			AB       BA
			A         A
*/

#include <iostream>

using namespace std;

void printLine(int n, int s, int m)
{
	for(int i=0;i<n-s;i++)
		cout << char('A'+i);
	for(int i=0;i<2*s-1;i++)
		cout << " ";
	for(int i=m;i>=0;i--)
		cout << char('A'+i);
    cout << endl;
}

int main()
{
	int n = 6;

	printLine(n, 0, n-2);
	for(int i=1;i<n;i++)
        printLine(n, i, n-i-1);

	return 0;
}

/*
	Print the following pattern :
	n = 7, lines = 4
	output :  7 
			  14 15
			  28 29 30 31
			  56 57 58 59 60 61 62 63
*/

#include <iostream>

using namespace std;

void printLine(int n, int length)
{
	for(int i=0;i<length;i++)
	{
		cout << n + i << " ";
	}
	cout << endl;
}

int main()
{
	int n, lines;
	cin >> n >> lines;

	int length = 1;
	for(int i=0;i<lines;i++)
	{
		printLine(n, length);
		length = 2 * length;
		n = 2 * n;
	}

	return 0;
}
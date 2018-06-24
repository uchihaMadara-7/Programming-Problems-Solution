#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void printLine(vector<int> pascal, int n)
{
	for(int i=0;i<=n;i++)
		cout << pascal[i] << " ";
	cout << endl;
}

void copy(vector<int> a, vector<int> &b)
{
	int size = a.size();
	for(int i=0;i<size;i++)
	{
		b[i] = a[i];
	}
}

void pascalTriangle(int n)
{
	vector<int> pascal(n);
	vector<int> display(n);

	display[0] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<i;j++)
		{
			display[j] = pascal[j] + pascal[j-1]; 
		}
		display[i] = 1;
		printLine(display, i);
		copy(display, pascal);
	}
}

int main()
{
    int n;
    cin >> n;

    pascalTriangle(n);
}

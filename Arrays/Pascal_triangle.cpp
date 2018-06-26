/*
	--- Question Statement ---
	
	Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n 
	as input and prints first n lines of the Pascal‟s triangle. Following are the first 6 rows of Pascal‟s Triangle.           
	1
	1 1
	1 2 1
	1 3 3 1
	1 4 6 4 1
	1 5 10 10 5 1 
*/

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

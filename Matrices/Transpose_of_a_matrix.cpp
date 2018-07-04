/*
	--- Question Statement ---

	Write a program to transpose a matrix and then print it.
*/

#include <iostream>

using namespace std;

void transpose(int **array, int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			swap(array[i][j], array[j][i]);
}

int main()
{
	int n;
	cin >> n;

	int **array = new int*[n];
	for(int i=0;i<n;i++)
		array[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> array[i][j];

	transpose(array, n);

	cout <<"------------" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << array[i][j] << " ";
		cout << endl;
	}

	return 0;
}

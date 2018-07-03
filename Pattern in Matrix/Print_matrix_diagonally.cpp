/*
	Print matrix diagonally:
	Example : 1  2  3  4
			  5  6  7  8
			  9  10 11 12
			  13 14 15 16

	output: 13 9 14 5 10 15 1 6 11 16 2 7 12 3 8 4
*/

#include <iostream>

using namespace std;

void printDiagonal(int **array, int x, int y, int n, int m)
{
	while(x < n && y < m)
	{
		cout << array[x][y] << " ";
		x ++;
		y ++;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int **array = new int*[n];
	for(int i=0;i<n;i++)
		array[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> array[i][j];

	for(int i=n-1;i>=0;i--)
		printDiagonal(array, i, 0, n, m);

	for(int i=1;i<m;i++)
		printDiagonal(array, 0, i, n, m);

	return 0;
}

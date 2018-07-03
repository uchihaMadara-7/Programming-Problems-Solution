/*
	Print matrix diagonally and zig-zag:
	Example : 1  2  3  4
			  5  6  7  8
			  9  10 11 12
			  13 14 15 16

	output: 13 14 9 5 10 15 16 11 6 1 2 7 12 8 3 4
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

void printDiagonal_r(int **array, int x, int y)
{
	while(x >= 0 && y >= 0)
	{
		cout << array[x][y] << " ";
		x --;
		y --;
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

	int count = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(count % 2)
			printDiagonal_r(array, n-1, count);
		else
			printDiagonal(array, i, 0, n, m);

		count ++;
	}

    int index = n - 2;
	for(int i=1;i<m;i++)
	{
		if(count % 2)
        {
			printDiagonal_r(array, index, m-1);
        }
		else
			printDiagonal(array, 0, i, n, m);

		count --;
		index --;
	}

	return 0;
}

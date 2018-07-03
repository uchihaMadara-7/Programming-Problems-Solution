/*
	Given a matrix, print and count all submatrix of size>=2 in which the columns
	are in sorted order individually.

	1 -2 6  0
	8  0 7 -3
	10 4 9 -2
	6  5 4  1

	output: total are: 5
*/

#include <iostream>

using namespace std;

void print(int **array, int x, int y, int size)
{
	int n = x + size;
	int m = y + size;

	for(int i=x;i<n;i++)
	{
		for(int j=y;j<m;j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << "--------" << endl;
}

bool isSortedCol(int **array, int x, int y, int size)
{
	int n = x + size;
	int m = y + size;
	int last;

	for(int j=0;j<m;j++)
	{
		last = array[0][j];
		for(int i=0;i<n;i++)
		{
			if(last <= array[i][j])
				last = array[i][j];
			else
				return false;
		}
	}

	return true;
}

void all_col_sorted_submatrix(int **array, int n)
{
	int count = 0;
	for(int size=2;size<=n;size++)
		for(int i=0;i<n-size+1;i++)
			for(int j=0;j<n-size+1;j++)
			{
				if(isSortedCol(array, i, j, size))
				{
					print(array, i, j, size);
					count ++;
				}
			}

	cout << "Total are : " << count << endl;
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

    all_col_sorted_submatrix(array, n);
	return 0;
}

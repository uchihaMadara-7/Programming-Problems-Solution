/*
	--- Question Statment ---

	Given a matrix of size n*n, print and count all the submatrix of size>=2
	in which the submatrix are in sorted order.
	example: 1 2   [1 2 3 4] is sorted but 1 2   [1 2 4 3] is not sorted.
	         3 4                           4 3 

  1 2 3 4
  3 4 2 1
  1 2 3 4
  4 5 6 1

  output: total are: 3
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
	cout << "-------" << endl;
}

bool isSorted(int **array, int x, int y, int size)
{
	int n = x + size;
	int m = y + size;
	int last = array[x][y];

	for(int i=x;i<n;i++)
	{
		for(int j=y;j<m;j++)
		{
			if(last <= array[i][j])
				last = array[i][j];
			else
                return false;
		}
	}

	return true;
}

void all_sorted_submatrix(int **array, int n)
{
	int count = 0;
	for(int size=2;size<=n;size++)
		for(int i=0;i<n-size+1;i++)
			for(int j=0;j<n-size+1;j++)
			{
				if(isSorted(array, i, j, size))
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

	all_sorted_submatrix(array, n);

	return 0;
}

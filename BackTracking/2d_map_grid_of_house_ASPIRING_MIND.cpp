/*
	--- Question Statment ---

	Given a map of 2D array grid of n*m (length and width)
	1 - house present
	0 - house absent
	Adjacent 1's are same house
	Develop a code to count total number of houses and max house width.

	Example : n = 3, m = 3
			  1 0 1
			  1 1 0
			  1 0 1

	output: Total houses are : 3
			Width of maximum : 4
*/

#include <iostream>
#include <climits>

using namespace std;

int countHouse(int **array, int row, int col, int x, int y, bool flag)
{
	static int count = 0;
	if(flag)
		count = 0;

	if(x > 0 && array[x-1][y] == 1)
	{
		count ++;
		array[x-1][y] = 0;
		countHouse(array, row, col, x-1, y, false);
	}

	if(x < row-1 && array[x+1][y] == 1)
	{
		count ++;
		array[x+1][y] = 0;
		countHouse(array, row, col, x+1, y, false);
	}

	if(y > 0 && array[x][y-1] == 1)
	{
		count ++;
		array[x][y-1] = 0;
		countHouse(array, row, col, x, y-1, false);
	}

	if(y < col-1 && array[x][y+1] == 1)
	{
		count ++;
		array[x][y+1] = 0;
		countHouse(array, row, col, x, y+1, false);
	}

	if(y < col-1 && x < row-1 && array[x+1][y+1] == 1)	
	{
		count ++;
		array[x+1][y+1] = 0;
		countHouse(array, row, col, x+1, y+1, false);
	}

	if(y < col-1 && x > 0 && array[x-1][y+1] == 1)	
	{
		count ++;
		array[x-1][y+1] = 0;
		countHouse(array, row, col, x-1, y+1, false);
	}

	if(y > 0 && x < row-1 && array[x+1][y-1] == 1)	
	{
		count ++;
		array[x+1][y-1] = 0;
		countHouse(array, row, col, x+1, y-1, false);
	}

	if(y > 0 && x > 0 && array[y-1][x-1] == 1)	
	{
		count ++;
		array[x-1][y-1] = 0;
		countHouse(array, row, col, x-1, y-1, false);
	}
	return count;
}

void totalHouse(int **array, int row, int col)
{
	int total = 0;
	int maxwidth = INT_MIN;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(array[i][j] == 1)
			{
				array[i][j] = 0;
				int width = countHouse(array, row, col, i, j, true) + 1;
				maxwidth = max(width, maxwidth);
				total ++;
			}
		}
	}

	cout << "Total houses are : " << total << endl;
	cout << "Max width is : " << maxwidth << endl;
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

	totalHouse(array, n, m);
    return 0;
}

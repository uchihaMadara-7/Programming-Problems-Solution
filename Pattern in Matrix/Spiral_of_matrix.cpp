/*
	Print matrix in spiral form:
	Example :  1  2   3   4 
	           5  6   7   8
	           9  10  11 12
	output: 1 2 3 4 8 12 11 10 9 5 6 7
*/

#include <iostream>

using namespace std;

void spiral(int **array, int n, int m)
{
	int i=0, j=0;

	int size = n * m;
	int c = 0;
	bool flag1 = false, flag2 = false;
	while(i < n && j < m)
	{
		flag1 = flag2 = false;
		for(int x=j;x<m;x++)
		{
			cout << array[i][x] << " ";
			flag2 = true;
		}
		i ++;

		for(int x=i;x<n;x++)
		{
			cout << array[x][m-1] << " ";
			flag1 = true;
		}
		m --;

		if(flag1)
		{
			for(int x=m-1;x>=j;x--)
			{
				cout << array[n-1][x] << " ";
			}
			n --;
		}

		if(flag2)
		{
			for(int x=n-1;x>=i;x--)
			{
				cout << array[x][j] << " ";
			}
			j ++;
		}

		c++;
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

	spiral(array, n, m);

	return 0;
}

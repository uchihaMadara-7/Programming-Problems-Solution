/*
	Print matrix in spiral form:
	Example :  1  2   3   4 
	           5  6   7   8
	           9  10  11 12
	output: 7 6 5 9 10 11 12 8 4 3 2 1
*/

#include <iostream>
#include <stack>

using namespace std;

void reverse_spiral(int **array, int n, int m)
{
	stack<int> revspi;
	int i=0, j=0;
	bool flag1 = false, flag2 = false;

	while(i < n && j < m)
	{
		flag1 = flag2 = false;
		for(int x=j;x<m;x++)
		{
			revspi.push(array[i][x]);
			//cout << array[i][x] << " ";
			flag2 = true;
		}
		i ++;

		for(int x=i;x<n;x++)
		{
			revspi.push(array[x][m-1]);
			flag1 = true;
		}
		m --;

		if(flag1)
		{
			for(int x=m-1;x>=j;x--)
				revspi.push(array[n-1][x]);
			n --;
		}

		if(flag2)
		{
			for(int x=n-1;x>=i;x--)
				revspi.push(array[x][j]);
			j ++;
		}
	}

	while(!revspi.empty())
	{
		cout << revspi.top() << " ";
		revspi.pop();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int **array = new int*[n];
	for(int i=0;i<n;i++)
		array[i] =new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> array[i][j];

	reverse_spiral(array, n, m);

	return 0;
}
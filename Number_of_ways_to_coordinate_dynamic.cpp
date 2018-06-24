#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int **array = new int*[n];

	long long int **paths = new long long int*[n+1];
	for(int i=0;i<n+1;i++)
		paths[i] = new long long int[m+1];

	for(int i=0;i<n+1;i++)
		paths[i][0] = 1;

	for(int i=0;i<m+1;i++)
		paths[0][i] = 1;

	for(int row=1;row<n+1;row++)
	{
		for(int col=1;col<m+1;col++)
		{
			paths[row][col] = paths[row-1][col] + paths[row][col-1];
		}
	}

	cout << paths[n][m] << endl;
	return 0;
}

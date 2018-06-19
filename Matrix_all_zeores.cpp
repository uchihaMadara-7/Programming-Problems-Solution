#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int **matrix = new int*[n];
	for(int i=0;i<n;i++)
		matrix[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
				cin >> matrix[i][j];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][j] = 10;
				for(int row = 0;row<m;row++)
				{
					if(matrix[i][row] != 0)
						matrix[i][row] = 10;
				}
				for(int col = 0;col<n;col++)
				{
					if(matrix[col][j] != 0)
						matrix[col][j] = 10;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
			for(int j=0;j<m;j++)
			{
					if(matrix[i][j] == 10)
						matrix[i][j] = 0;
					cout << matrix[i][j] << " ";
			}
		cout << endl;
	}

	return 0;
}



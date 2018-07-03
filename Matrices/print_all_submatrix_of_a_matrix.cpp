/*

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/

#include <iostream>

using namespace std;

void printmatrix(int **array, int x, int y, int size)
{
	int n = x + size;
	int m = y + size;

	for(int i=x;i<n;i++)
	{
		for(int j=y;j<m;j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

void all_submatrix(int **array, int n)
{
	for(int size=2;size<=n;size++)
    	for(int i=0;i<n-size+1;i++)
    		for(int j=0;j<n-size+1;j++)
    			printmatrix(array, i, j, size);
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

    all_submatrix(array, n);
    return 0;
}

/*
	--- Question Statement ---

	Print and count all submatrix such that the sum of submatrix is equal to given k.
	Example : n = 4, k = 9
			  1 2 3 4
			  4 3 2 1
			  1 2 3 4
			  4 2 2 1

	output :   1 2
	           4 2
	           ---
	           2 3 
	           2 2 
			   ---
	         Total count is : 2
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

	cout << "------------ " << endl;
}

int getsum(int **array, int x, int y, int size)
{
	int n = x + size;
	int m = y + size;

	int sum = 0;
	for(int i=x;i<n;i++)
		for(int j=y;j<m;j++)
			sum += array[i][j];

	return sum;
}

void all_submatrix(int **array, int n, int k)
{
	int count = 0;

	for(int size=2;size<=n;size++)
		for(int i=0;i<n-size+1;i++)
			for(int j=0;j<n-size+1;j++)
			{
				if(getsum(array, i, j, size) == k)
				{
					count ++;
					print(array, i, j, size);
				}
			}

	cout << "Total count are : " << count << endl;
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

	int k;
	cin >> k;

	all_submatrix(array, n, k);
	return 0;
}

/*
	--- Question Statment ---
	
	Given a matrix of size n*n, Find and print total number of unique elements in the matrix. Unique elements are those that
	occur only once.
	Example : 1 2 3
	          4 5 6
		  1 2 7
	output : 3 4 5 6 7
	         total = 5
*/

#include <iostream>
#include <map>

using namespace std;

int uniqueElements(int **matrix, int n)
{
	map<int,int> hash;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(hash.find(matrix[i][j]) != hash.end())
			{
				hash[matrix[i][j]] += 1;
			}
			else
			{
				hash[matrix[i][j]] = 1;
			}
		}
	}

	int count = 0;
	for(map<int,int>::iterator i= hash.begin();i!=hash.end();i++)
	{
		if(i->second == 1)
		{
			cout << i->first << " ";
			count ++;
		}
	}
	cout << endl;

	return count;
}

int main()
{
	int n;
	cin >> n;
	int **matrix = new int*[n];
	for(int i=0;i<n;i++)
		matrix[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> matrix[i][j];

	cout <<"Total unique are : " << uniqueElements(matrix, n) << endl;
	return 0;
}

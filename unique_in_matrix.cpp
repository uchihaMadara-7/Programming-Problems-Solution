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

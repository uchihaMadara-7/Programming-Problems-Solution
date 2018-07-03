/*
	Find total number of pairs in two arrays such that a[i]^b[j] > b[i]^a[j] for i < j
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int m;
	cin >> m;
	int *brray = new int[m];

	for(int i=0;i<m;i++)
		cin >> brray[i];

	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(pow(array[i], brray[j]) > pow(brray[i], array[j]))
			{
				count++;
				cout << array[i] << "  " << brray[j] << endl;
			}
		}
	}

	cout << "Total are: " << count << endl;
	return 0;
}

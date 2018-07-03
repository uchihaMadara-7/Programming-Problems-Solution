/*
	--- Question Statement ---
	
	Find the total number of pairs whose sum equals to a given number k.
	Example: array = [1 2 3 4 5 6]   k = 7
	output: 3 
	Explanation: (1,6) (2,5) (3,4)
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

	int k;
	cin >> k;

	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(fabs(array[i] - array[j]) == k)
			{
				cout << array[i] << " " << array[j] << endl;
				count ++;
			}
		}
	}

	cout << count << endl;
	return 0;
}

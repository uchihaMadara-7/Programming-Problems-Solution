/*
	--- Question Statement ---

	Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. 
	The functions should put all 0s first, then all 1s and all 2s in last.

	Input :  0 1 1 0 1 2 1 2 0 0 0 1
	Output : 0 0 0 0 0 1 1 1 1 1 2 2
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	int i1 = 0, i2 = 0, i3 = n-1;
	while(i2 <= i3)
	{
		if(array[i2] == 1)
			i2 ++;
		else if(array[i2] == 0)
		{
			swap(array[i1], array[i2]);
			i1 ++;
			i2 ++;
		}
		else
		{
			swap(array[i3], array[i2]);
			i3 --;
		}
	}

	for(int i=0;i<n;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

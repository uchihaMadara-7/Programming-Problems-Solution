/*
	--- Question Statement ---

Given an array of integers (both odd and even), the task is to sort them in such a way that the 
first part of the array contains odd numbers sorted in descending order, rest portion contains even 
numbers sorted in ascending order.

Examples:

Input  : A[] = {1, 2, 3, 5, 4, 7, 10}
Output : A[] = {7, 5, 3, 1, 2, 4, 10}

Input  : A[] = {0, 4, 5, 3, 7, 2, 1}
Output : A[] = {7, 5, 3, 1, 0, 2, 4} 

*/

#include<iostream>
#include<sort>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int *array = new int[n];

		for(int i=0;i<n;i++)
		{
			cin >> array[i];
			if(array[i] % 2)
				array[i] *= -1;
		}

		sort(array, array+n);

		for(int i=0;i<n;i++)
		{
			if(array[i] < 0)
				array[i] *= -1;
			else
				break;
		}

		for(int i=0;i<n;i++)
			cout << array[i] << " ";
		cout << endl;
	}

	return 0;
}
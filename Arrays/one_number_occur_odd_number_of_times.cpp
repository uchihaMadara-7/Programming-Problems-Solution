/*
	--- Question Statement ---
	
	Given an array with every element appears even number of times, and only one element appears odd number of times.
	Find the number that appears odd number of times.
	Example: [1,2,2,3,3] output: 1
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

	int xors = 0;
	for(int i=0;i<n;i++)
		xors ^= array[i];

	cout << xors << endl;
	return 0;
}

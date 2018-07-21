/*
	--- Question Statement ---

Minimum number of coins required to fullfil a given value of x. Quantity of a single coin is infinte.

Example: 3
		 1 5 8
		 15

output: 3 

Explanation: 5,5,5 - 3 coins of 5 denomination are enough to make 15.

*/

#include<iostream>
#include<climits>
using namespace std;

int minim = INT_MAX;
int count = 0;

void minWays(int *array, int n, int sum , int current = 0, int ways = 0)
{
	if(sum == 0)
	{
		count ++;
		if(ways < minim)
			minim = ways;

		return;
	}

	if(sum < 0)
		return;

	if(current >= n)
			return;

	minWays(array, n, sum-array[current], current, ways+1);
	minWays(array, n, sum, current+1, ways);
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	int x;
	cin >> x;

	minWays(array, n, x);
	cout << "Minimum number of coins : " << minim << endl;
	cout << "Total number of ways : " << count << endl;

	return 0;
}
/*
	--- Question Statement ---

	Total number of squares on a matrix of size n*n.
	Example : n = 3
	output : 14

	Solution : sum squares of first n terms
	Example : n = 3
	output : 1 + 4 + 9 = 14
	can be computed using formula : n*(n+1)*(2n+1)/6
*/

#include <iostream>

using namespace std;

int squares(int n, int size)
{
	int count = 0;
	for(int i=0;i<n-size+1;i++)
		for(int j=0;j<n-size+1;j++)
			count ++;

	return count;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for(int i=1;i<=n;i++)
		count += squares(n, i);

	cout << count << endl;

	return 0;
}

/*
	--- Question Statement ---

Given two integers m & n, find the number of possible sequences of length n such that each of the 
next element is greater than or equal to twice of the previous element but less than or equal to m.

Input:
First line consists of test case T. Only line of every test case consists of 2 integers M and N.

Output:
Single line output, number of sequences possible.

Constraints:
1<=T<=100
1<=M,N<=100

Example:
Input:
2
10 4
5 2
Output:
4
6

Explanation:
Input : m = 10, n = 4
Output : 4
There should be n elements and value of last
element should be at-most m.
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9},
                 {1, 2, 4, 10}, {1, 2, 5, 10}

Input : m = 5, n = 2
Output : 6
The sequences are {1, 2}, {1, 3}, {1, 4},
                  {1, 5}, {2, 4}, {2, 5}

*/

#include<iostream>

using namespace std;

int totalSequence(int n, int m)
{
	if(m < n)
		return 0;

	if(n == 0)
		return 1;

	return totalSequence(n-1, m/2) + totalSequence(n, m-1);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		cout << totalSequence(n, m) << endl;
	}

	return 0;
}
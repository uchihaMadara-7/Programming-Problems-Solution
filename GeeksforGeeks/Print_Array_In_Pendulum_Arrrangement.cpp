/*
	--- Question Statment ---

Write a program to input a list of n integers in an array and arrange them 
in a way similar to the to-and-fro movement of a Pendulum.

 1) The minimum element out of the list of integers, must come in center 
    position of array. If there are even elements, then minimum element 
    should be moved to (n-1)/2 index (considering that indexes start
    from 0)
 2) The next number (next to minimum) in the ascending order, goes to the 
    right, the next to next number goes to the left of minimum number and 
    it continues like a Pendulum.

Constraints:
1<=T<=500
1<=N<=100
1<=a[i]<=1000

Example:
Input:
2
5
1 3 2 5 4
5
11 12 31 14 5

Output:
5 3 1 2 4
31 12 5 11 14

*/

#include<iostream>
#include<queue>
#define heap priority_queue<int, vector<int>, greater<int>>
using namespace std;

int main()
{
	int t, a;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> pendulum;
		heap minHeap;
		for(int i=0;i<n;i++)
		{
			cin >> a;
			minHeap.push(a);
		}

		pendulum.push_back(minHeap.top());
		minHeap.pop();

		for(int i=1;i<n;i++)
		{
			if(i%2)
			{
				pendulum.push_back(minHeap.top());
			}
			else
			{
				pendulum.insert(pendulum.begin(), minHeap.top());
			}

			minHeap.pop();
		}

		for(int i=0;i<n;i++)
			cout << pendulum[i] << " ";
		cout << endl;
	}

	return 0;
} 
















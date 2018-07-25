/*
	--- Question Statement ---

A sequence X_1, X_2, ..., X_n is fibonacci-like if:

    n >= 3
    X_i + X_{i+1} = X_{i+2} for all i + 2 <= n

Given a strictly increasing array A of positive integers forming a sequence, find the 
length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number 
of elements (including none) from A, without changing the order of the remaining 
elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].

Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].

Note:

    3 <= A.length <= 1000
    1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
    
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int lenLongestFibSubseq(vector<int>& a) 
{
    int size = a.size();
    int maxim = 0;
    
    set<int> fib(a.begin(), a.end());
    
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            int first = a[i];
            int second = a[j];
            
            int length = 2;
            
            while(fib.find(first+second) != fib.end())
            {
                int temp = first;
                first = second;
                second = temp + second;
                length ++;
            }
            
            maxim = max(maxim, length);
        }
    }
    
    return maxim>=3?maxim:0;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	cout << lenLongestFibSubseq(a) << endl;

	return 0;
}
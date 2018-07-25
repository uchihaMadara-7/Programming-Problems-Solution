/*
	--- Question Statement ---

Given an array of size N , print the total count of sub-arrays having their sum equal to 0

Input: First line of the input contains an integer T denoting the number of test cases. 
Each test case consists of two lines. First line of each test case contains an Integer N 
denoting the size of the array and the second line contains N space separated integers.

Output: Corresponding to each test case, print the total number of subarrays whose sum is 
equal to 0.

Constraints:    
1<= N <= 10000
-100 <= A[i] <= 100 where i <= N

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4

*/

#include<iostream>
#include<map>
using namespace std;

int countSubarray(int *array, int n)
{
    int count = 0;
    int sum = 0;
    
    map<int,int> hash;
    
    for(int i=0;i<n;i++)
    {
        sum += array[i];
    
        if(sum == 0)
            count ++;
    
        if(hash.find(sum) != hash.end())
        {
            count += hash[sum];
        }
            
        hash[sum] ++;
    }
    
    return count;
}

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
	        cin >> array[i];
	        
	    cout << countSubarray(array, n) << endl;
	}
	
	return 0;
}
/*
	--- Qustion Statement ---

Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that 
satisfies a^2 + b^2 = c^2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

*/

#include<algorithm>
#include<cmath>
using namespace std;

bool binary(int *array, int low, int high, int key)
{
    if(high < low)
        return false;
 
    int mid = low + (high-low)/2;
    
    if(pow(array[mid],2) == key)
        return true;
    
    if(pow(array[mid],2) > key)
        return binary(array, low, mid-1, key);
    return binary(array, mid+1, high, key);
}

bool isTriplet(int *array, int n)
{
    sort(array, array+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(binary(array, 0, n-1, pow(array[i],2)+pow(array[j],2)))
                return true;
        }
    }
    
    return false;
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
            
        if(isTriplet(array, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
	return 0;
}
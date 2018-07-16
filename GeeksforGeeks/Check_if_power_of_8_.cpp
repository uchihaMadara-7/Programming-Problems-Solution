/*
	--- Question Statement ---

Given a positive integer N, The task is to find if it is a power of eight or not.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases 
follow. Each test case contains an integer N.

Output:
In new line print "Yes" if it is a power of 8, else print "No".

Constraints:
1<=T<=100
1<=N<=1018

Example:
Input:
2
64
75
Output:
Yes
No

*/

#include<iostream>
using namespace std;

int bits = sizeof(long long int)*8;

bool isPower8(long long int n)
{
    int count = 0;
    for(int i=0;i<bits;i++)
        if(n & (long long int)1 << i)
            count ++;
            
    if(count != 1)
        return false;
        
    count = 0;
    for(int i=0;i<bits;i++)
    {
        if(n & (long long int)1 << i)
            break;
        count ++;
    }
    
    return count%3 == 0;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long int n;
        cin >> n;
        
        if(isPower8(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
	return 0;
}
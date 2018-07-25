/*
	--- Question Statment ---

Given an array of numbers, the task is to print only those numbers which have only 
1, 2 and 3 as their digits.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. First line of each 
test case contains an integer N and the second line contains N space separated 
array elements.

Output:
For each test case, In new line print the required elements in increasing order. if 
there is no such element present in the array print "-1".

Constraints:
1<=T<=100
1<=N<=106
1<=A[i]<=106

Example:
Input:
2
3
4 6 7
4
1 2 3 4

Output:

-1
1 2 3

*/

#include<iostream>
#include<algorithm>
using namespace std;

bool onetwothree(int n)
{
    while(n>0)
    {
        int remain = n % 10;
        if(!(remain == 1 || remain == 2 || remain == 3))
            return false;
            
        n/=10;
    }
    
    return true;
}

void Contain(int *array, int n)
{
    bool flag = false;
    sort(array, array+n);
    for(int i=0;i<n;i++)
    {
        if(onetwothree(array[i]))
        {
            flag = true;
            cout << array[i] << " ";
        }
    }
    
    if(!flag)
        cout << "-1 ";
        
    cout << endl;
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
            
        Contain(array, n);    
    }
    
	return 0;
}
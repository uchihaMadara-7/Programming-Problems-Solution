/*
	--- Question Statment ---

Given an array having no duplicates, which can be of 4 types
1.  Ascending
2.  Descending
3.  Descending Rotated
4.  Ascending Rotated

Your task is to print which type of array it is and the maximum element of that array.

Input:
The first line of input contains an integer T denoting the no test cases. Then T test caes follow. 
The first line of input contains an integer n denoting the size of the array. Then in the next line 
are N space separated values of the array.

Output:
For each test case print the largest element in the array and and integer x denoting the type of the 
array.

Constraints:
1<=T<=100
4<=n<=100
1<=A[]<=10000

Example:
Input:
2
5
2 1 5 4 3
5
3 4 5 1 2

Output:
5 3
5 4

*/

#include<iostream>
using namespace std;

bool isAscending(int *array, int n)
{
    for(int i=0;i<n-1;i++)
        if(array[i] >= array[i+1])
            return false;
    return true;
}

bool isDescending(int *array, int n)
{
    for(int i=n-1;i>0;i--)
        if(array[i] >= array[i-1])
            return false;
    return true;
}

int DesRotate(int *array, int n)
{
    int i = n-1;
    for(;i>0;i--)
        if(array[i] >= array[i-1])
            return array[i];
}

int AscRotate(int *array, int n)
{
    int i = 0;
    for(;i<n-1;i++)
        if(array[i] >= array[i+1])
            return array[i];
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
            
        if(array[0] < array[n-1])
        {
            if(isAscending(array, n))
            {
                cout << array[n-1] << " 1"  << endl;
            }
            else
            {
                cout << DesRotate(array, n) << " 3"  << endl;
            }
        }
        else
        {
            if(isDescending(array, n))
            {
                cout << array[0] << " 2" << endl;
            }
            else
            {
                cout << AscRotate(array, n) << " 4" << endl;
            }
        }
            
    }
    
	return 0;
}